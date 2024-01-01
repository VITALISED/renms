/**
 * @file GcMsgBeaconManager.h
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

#include <simulation/environment/scanning/GcMarkerPoint.h>
#include <toolkit/system/memory/pools/TkMemoryPool.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <atlas/gcatlasdiscovery.meta.h>

SKYSCRAPER_BEGIN

class cGcMsgBeacon : public AutoPooled<5>
{
  public:
    enum UploadStatus
    {
        eFailed,
        eSucceeded,
        eUnknown,
    };

    enum ProfanityState
    {
        Unchecked,
        Processing,
        DoneAndProfane,
        DoneAndClean,
    };

    enum DisplayNameState
    {
        _Unchecked,
        _Processing,
        Done,
    };

    enum PermissionState
    {
        __Unchecked,
        __Processing,
        DoneAndPassed,
        DoneAndBlocked,
    };

    cGcAtlasDiscovery mDiscovery;
    TkHandle mNodeHandle;
    bool mbPlayerOwned;
    bool mbDestroyPending;
    cGcMsgBeacon::UploadStatus meUploadStatus;
    cGcMarkerPoint mMarker;
    bool mbHasMarker;
    std::atomic<cGcMsgBeacon::ProfanityState> meProfanityState;
    std::atomic<cGcMsgBeacon::DisplayNameState> meDisplayNameState;
    std::atomic<cGcMsgBeacon::PermissionState> mePermissionState;
};

class cGcMsgBeaconManager
{
  public:
    struct Data : AutoPooled<5>
    {
        cTkVector<uint64_t> mRequestsInFlight;
        cTkVector<std::shared_ptr<cGcMsgBeacon>> mRemoteBeacons;
        cTkVector<std::shared_ptr<cGcMsgBeacon>> mRemoteAsyncOpsBeacons;
        cTkSmartResHandle mBeaconRes;
    };

    cGcMsgBeaconManager::Data *mpData;
};

SKYSCRAPER_END