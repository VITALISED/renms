/**
 * @file GcBaseBuildingPersistentBuffer.h
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

#include <gamestate/GcPersistencyHandle.h>
#include <networking/GcNetworkPlayer.h>
#include <networking/GcNetworkSynchronisedBuffer.h>
#include <networking/messages/GcNetworkSyncMessages.h>
#include <toolkit/core/types/TkID.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <toolkit/networking/TkUserIdBase.h>
#include <toolkit/utilities/string/TkString.h>

#include <gamestate/basebuilding/gcpersistentbbobjectdata.meta.h>

SKYSCRAPER_BEGIN

template <typename T>
class PersistentData
{
  public:
    virtual ~PersistentData();
    virtual bool IsValid();

    T mData;
    uint16_t miInc;
};

class cGcBaseBuildingPersistentBuffer : public cGcNetworkSynchronisedBuffer
{
  public:
    virtual ~cGcBaseBuildingPersistentBuffer();
    virtual uint16_t GenerateHashValue(int);
    virtual std::shared_ptr<cGcNetworkHashMessage> *GenerateHashMessage(std::shared_ptr<cGcNetworkHashMessage> *result);
    virtual std::shared_ptr<cGcNetworkSyncMessage> *GenerateSyncMessage(
        std::shared_ptr<cGcNetworkSyncMessage> *result, int);
    virtual void ApplySyncMessage(const cGcNetworkSyncMessage *, cGcNetworkPlayer *);
    virtual bool HasNetworkOwner(cTkUserIdBase<cTkFixedString<64, char>> *);

    void GetObjectCountsById(
        const TkID<128> &lID, const cTkVector3 &lLocalPosition, uint32_t &liOutPlanetCount, uint32_t &liOutRegionCount,
        uint64_t &lu64Address);
    bool HasNetworkOwner(cTkUserIdBase<cTkFixedString<64, char>> &lOutOwnerId);
    void InitializeFromData(const cTkDynamicArray<cGcPersistentBBObjectData> &lBaseBuildingData);
    void RefundBlacklistedBuildingObjects();
    void RemoveDataFromRegion(uint16_t liDataIndex);
    GcPersistencyHandle &StoreBaseBuildingObject(
        const TkID<128> &lID, const cTkVector3 &lLocalUp, const cTkVector3 &lLocalAt,
        const cTkVector3 &lLocationPosition, uint64_t luRegionSeed, uint64_t lUserData, uint64_t lUA);
    bool UpdateBaseBuildingObject(GcPersistencyHandle lHandle, uint64_t luNewTimeStamp, uint64_t luNewUserData);

    class BaseBuildingPersistentData : public PersistentData<cGcPersistentBBObjectData>
    {
      public:
        virtual ~BaseBuildingPersistentData();

        bool IsValid();
    };

    cTkVector<cGcBaseBuildingPersistentBuffer::BaseBuildingPersistentData> maBaseBuildingObjects;
    robin_hood::detail::Table<
        true, 80, uint64_t, std::vector<unsigned short>, robin_hood::hash<uint64_t, void>, std::equal_to<uint64_t>>
        maCurrentPlanetObjects;
    uint64_t muCurrentAddress;
    bool mbDebugPositions;
    cTkUserIdBase<cTkFixedString<64, char>> mNetworkOwnerId;
    unsigned int miBufferIndex;
};

SKYSCRAPER_END