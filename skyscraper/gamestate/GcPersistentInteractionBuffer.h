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
#include <toolkit/maths/utilities/spatial/TkVector3KD.h>
#include <toolkit/networking/TkUserIdBase.h>

#include <gamestate/interactions/gcinteractionbuffertype.meta.h>
#include <gamestate/interactions/gcinteractiondata.meta.h>

SKYSCRAPER_BEGIN

class cGcNetworkPlayer;

class cGcPersistentInteractionBuffer : public cGcNetworkSynchronisedBuffer
{
  public:
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

    virtual ~cGcPersistentInteractionBuffer() { EMPTY_CALL_DESTRUCTOR(); }
    virtual sHashValue *GetHashValue(sHashValue *result, unsigned int);
    virtual uint64_t GetHashTimestamp();
    virtual uint16_t GenerateHashValue(int);
    virtual void OnHashOffsetChanged(int);
    virtual std::shared_ptr<cGcNetworkHashMessage> *GenerateHashMessage(std::shared_ptr<cGcNetworkHashMessage> *result);
    virtual std::shared_ptr<cGcNetworkSyncMessage> *GenerateSyncMessage(
        std::shared_ptr<cGcNetworkSyncMessage> *result, int);
    virtual void ApplySyncMessage(const cGcNetworkSyncMessage *, cGcNetworkPlayer *);
    virtual bool HasNetworkOwner(cTkUserIdBase<cTkFixedString<64, char>> *);
    virtual bool ShouldSyncWithPlayer(cGcNetworkPlayer *);
};

template <typename T>
struct cGcVariablePersistentInteractionBuffer : public cGcPersistentInteractionBuffer
{
    cTkVector<T> mVariableData;
    const int mkiSyncMessageMaxSize;
};

SKYSCRAPER_END