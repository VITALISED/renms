/**
 * @file GcPersistentInteractionBuffer.h
 * @author VITALISED & Contributors
 * @since 2023-12-09
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <skyscraper.h>

#include <networking/GcNetworkSynchronisedBuffer.h>
#include <networking/messages/GcNetworkSyncMessages.h>
#include <simulation/environment/regiondata/terrain/GcRegionTerrain.h>
#include <toolkit/maths/utilities/spatial/TkVector3KD.h>
#include <toolkit/networking/TkUserIdBase.h>

#include <gamestate/interactions/gcinteractionbuffer.meta.h>
#include <gamestate/interactions/gcinteractionbuffertype.meta.h>
#include <gamestate/interactions/gcinteractiondata.meta.h>

SKYSCRAPER_BEGIN

class cGcNetworkPlayer;

class cGcPersistentInteractionBuffer : public cGcNetworkSynchronisedBuffer
{
  public:
    virtual ~cGcPersistentInteractionBuffer();
    virtual sHashValue &GetHashValue(unsigned int);
    virtual uint64_t GetHashTimestamp();
    virtual uint16_t GenerateHashValue(int);
    virtual void OnHashOffsetChanged(int);
    virtual std::shared_ptr<cGcNetworkHashMessage> &GenerateHashMessage();
    virtual std::shared_ptr<cGcNetworkSyncMessage> &GenerateSyncMessage(int);
    virtual void ApplySyncMessage(const cGcNetworkSyncMessage *, cGcNetworkPlayer *);
    virtual bool HasNetworkOwner(cTkUserIdBase<cTkFixedString<64, char>> *);
    virtual bool ShouldSyncWithPlayer(cGcNetworkPlayer *);

    const cGcInteractionData *GetInteraction(const cTkVector3 &lPosition);
    const cGcInteractionData *GetInteractionCheckingFurthest(const cTkVector3 &lPosition, float lfRadius);
    const cGcInteractionData *GetInteractionOnPlanet(const cTkVector3 &lPlanetOffsetPosition, float lfRadius);
    const cGcInteractionData *GetMatchingInteraction(
        const cTkVector3 &lPosition, uint64_t muiMatchingValue, float lfRadius);
    const cGcInteractionData *GetNearestInteraction(const cTkVector3 &lPosition, float &lDistance);
    void InitializeFromData(const cGcInteractionBuffer &lBufferData);
    void InternalDoTreeRebuildNoLock();
    void LoadGalacticAddressBuffers(const uint64_t &lu64Address);
    void PopulateBufferData(cGcInteractionBuffer &lBufferData);
    void RefreshRelevantComponents(
        const cTkVector3 &lUpdatedLocation, cTkUserIdBase<cTkFixedString<64, char>> &lPlayerId, uint64_t lData);
    bool RegionHasInteractionsPlanetPosition(cGcRegionTerrain *lpRegion);
    void SaveInteraction(const cTkVector3 &lPosition, const cGcInteractionData &lData, bool lbReplace, float lfRadius);
    void StoreInteraction(const cGcInteractionData &lData, bool lbReplace, float lfRadius);
    void Update(float lfTimeStep);

    union {
        const int kiDistressSignalMaxBufferSize;
        const int kiCrateMaxBufferSize;
        const int kiDestructableMaxBufferSize;
        const int kiCostMaxBufferSize;
        const int kiBuildingMaxBufferSize;
        const int kiCreatureMaxBufferSize;
        const int kiMaintenanceMaxBufferSize;
        const int kiPersonalMaxBufferSize;
        const int kiPersonalMaintenanceMaxBufferSize;
        const int kiFireteamSyncMaxBufferSize;
        const int kiNGuiPageSize;
    };

    int miLastBufferIndex;
    uint64_t muCurrentAddress;
    eInteractionBufferType meType;
    cTkDynamicArray<cGcInteractionData> maBufferData;
    int miCurrentPos;
    cTkVector3MetaKD<int, -1> mSavedInteractionsDB;
    // nanoflann::KDTreeSingleIndexAdaptor<
    //     nanoflann::L2_Simple_Adaptor<float, cTkVector3MetaKD<int, -1>, float>, cTkVector3MetaKD<int, -1>, 3,
    //     uint64_t> mTree;
    nanoflann::KDTreeSingleIndexAdaptor mTree;
    int miNGuiOffset;
    float mfTimeSinceLastSavedInteraction;
    float mfFurthestPointDistance;
    cTkVector3 mFurthestPoint;
    void *mMutex;
    bool mbPersistenceActive;
    bool mbTreeHasData;
    bool mbTreeNeedsRebuild;
};

template <typename T>
class cGcVariablePersistentInteractionBuffer : public cGcPersistentInteractionBuffer
{
  public:
    enum eLocation;

    virtual std::shared_ptr<cGcNetworkSyncMessage> &GenerateSyncMessage(int);
    virtual void ApplySyncMessage(const cGcNetworkSyncMessage *, cGcNetworkPlayer *);
    virtual bool HasNetworkOwner(cTkUserIdBase<cTkFixedString<64, char>> *);
    virtual bool ShouldSyncWithPlayer(cGcNetworkPlayer *);

    void InitializeFromVariableData(const cGcInteractionBuffer &lBufferData, const cTkDynamicArray<T> &lVariableData);
    cGcInteractionData &SaveVariableInteraction(
        const cTkVector3 &lPosition, cGcVariablePersistentInteractionBuffer<T>::eLocation leLocation, const T &lData,
        float lfRadius, bool);

    enum eLocation
    {
        ELocation_UserSpace,
        ELocation_OnPlanet,
        ELocation_InFreighter,
        ELocation_InBase,
        ELocation_InSpaceStation,
        ELocation_InSpace,
        ELocation_Frigate,
        ELocation_NumTypes,
    };

    cTkVector<T> mVariableData;
    const int mkiSyncMessageMaxSize;
};

SKYSCRAPER_END