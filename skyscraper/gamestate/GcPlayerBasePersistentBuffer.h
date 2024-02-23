/**
 * @file GcPlayerBasePersistentBuffer.h
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

#include <basebuilding/GcBaseBuildingBaseLayout.h>
#include <basebuilding/GcBaseLinkGrid.h>
#include <basebuilding/GcBaseLinkGroups.h>
#include <gamestate/GcBaseBuildingPersistentBuffer.h>
#include <gamestate/GcPersistencyHandle.h>
#include <networking/GcNetworkSynchronisedBuffer.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>

#include <gamestate/basebuilding/gcbaseautopowersetting.meta.h>
#include <gamestate/basebuilding/gcbasebuildingentry.meta.h>
#include <gamestate/basebuilding/gcpersistentbaseentry.meta.h>
#include <gamestate/basebuilding/gcpersistentbasetypes.meta.h>
#include <gamestate/gcgamemode.meta.h>
#include <reality/gcdiscoveryowner.meta.h>
#include <user/gcpersistentbasedifficultydata.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerBasePersistentBuffer : public cGcNetworkSynchronisedBuffer
{
  public:
    struct PlayerBasePersistentData;

    virtual ~cGcPlayerBasePersistentBuffer();
    virtual uint16_t GenerateHashValue(int);
    virtual void OnHashOffsetChanged(int);
    virtual std::shared_ptr<cGcNetworkHashMessage> &GenerateHashMessage();
    virtual std::shared_ptr<cGcNetworkSyncMessage> &GenerateSyncMessage(int);
    virtual void ApplySyncMessage(const cGcNetworkSyncMessage *, cGcNetworkPlayer *);
    virtual bool HasNetworkOwner(cTkUserIdBase<cTkFixedString<64, char>> *);

    void AddAmountToGrid(
        GcPersistencyHandle lPartHandle, int liAmount, bool lbPartOnly, int liDependant, bool lbDontBroadcast);
    void AddBaseObjects(const cTkVector<cGcPlayerBasePersistentBuffer::PlayerBasePersistentData> &lObjects);
    void ApplySyncDataToObject(int liObjIndex, cGcPersistentBaseEntry &lNewData, uint64_t lu64NewRegionId);
    void ApplySyncRemoveObject(int liObjIndex, bool lbLinkConnectionsChanged, bool lbLinkGridDataChanged);
    bool AreObjectsOnSameGrid(GcPersistencyHandle lHandle1, GcPersistencyHandle lHandle2);
    bool AreObjectsTransferLinked(int liObjIndex1, int liObjIndex2);
    void CheckDiscoveryOwnerData();
    void ClaimPlayerBase(
        ePersistentBaseTypes leBaseType, const cTkPhysRelMat34 &lBaseMatrix, uint64_t lUA,
        cTkUserIdBase<cTkFixedString<64, char>> &lOwnerId);
    void ClearAndUnClaimBase();
    void ClearPlayerBase();
    int CountObjectsById(const TkID<128> &lID, const cTkVector3 &lLocalPosition, int liOutRegionCount);
    int CreateNewLinkGrid();
    GcPersistencyHandle &FindBaseBuildingObject(const TkID<128> &lID, const cTkVector3 &lLocalPosition);
    void ForceAddNodesAroundPlayer(cTkVector3 &lPlayerPosition, float lfRadius);

    struct PlayerBasePersistentData : PersistentData<cGcPersistentBaseEntry>
    {
        uint64_t muRegionId;
        uint16_t muiLinkIndex;
        uint16_t muiGridIndex;
        const cGcBaseBuildingEntry *mpBuildingEntry;
    };

    struct sStats
    {
        bool mbHasTeleporter;
        bool mbHasMainframe;
        bool mbHasParagonGenerator;
        uint16_t muStorageContainers;
    };

    cTkVector<cGcPlayerBasePersistentBuffer::PlayerBasePersistentData> maBaseBuildingObjects;
    uint64_t muCurrentAddress;
    uint64_t muiLastUpdateTimestamp;
    cTkPhysRelMat34 mBaseMatrix;
    uint64_t muBaseUA;
    uint64_t muBaseUserData;
    cTkFixedString<64, char> macRID;
    cGcDiscoveryOwner mOwner;
    cTkFixedString<64, char> mName;
    int miBaseVersion;
    int miOriginalBaseVersion;
    ePersistentBaseTypes meBaseType;
    cTkUserIdBase<cTkFixedString<64, char>> mNetworkOwnerId;
    cTkUserIdBase<cTkFixedString<64, char>> mLastEditedById;
    cTkFixedString<64, char> mLastEditedByUsername;
    cGcBaseBuildingBaseLayout *mpLayoutHandle;
    unsigned int muiValidObjectsCount;
    unsigned int muiExpectedObjectsCount;
    unsigned int muiLowestInvalidIndex;
    cTkVector3 mScreenshotPosition;
    cTkVector3 mScreenshotAt;
    cGcBaseLinkMap mLinkMap;
    cTkVector<cGcLinkGrid> mLinkGrids;
    bool mbRegenerateLinkGrids;
    bool mbIsReported;
    bool mbIsFeatured;
    bool mbIsHidden;
    eBaseAutoPowerSetting meAutoPowerSetting;
    cGcPlayerBasePersistentBuffer::sStats mStats;
    bool mbStatsDirty;
    int miNGuiOffset;
    bool mbDebugPositions;
    cGcGameMode mGameMode;
    cGcPersistentBaseDifficultyData mDifficulty;
};

SKYSCRAPER_END