/**
 * @file GcDiscoveryManager.h
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

#include <gamestate/GcDiscoveryCommon.h>
#include <gamestate/GcDiscoverySearch.h>
#include <networking/GcNetworkRpcCall.h>
#include <toolkit/utilities/containers/TkStackContainer.h>

#include <atlas/gcatlasdiscovery.meta.h>
#include <gamestate/gcuniverseaddressdata.meta.h>

SKYSCRAPER_BEGIN

class cGcAsyncOpsTempDiscovery
{
  public:
    enum ProfanityState
    {
        Unchecked,
        Processing,
        Done,
    };

    enum DisplayNameState
    {
        _Unchecked,
        _Processing,
        _Done,
    };

    std::atomic<cGcAsyncOpsTempDiscovery::ProfanityState> meProfanityState;
    std::atomic<cGcAsyncOpsTempDiscovery::DisplayNameState> meDisplayNameState;
    cGcAtlasDiscovery mDiscovery;
    bool mbDiscovered;
    bool mbClean;
};

class IDiscoveryManagerEventHandler
{
  public:
    virtual void DiscoveryQueryCompleted(
        const cGcUniverseAddressData *, const eDiscoveryType, const bool, const uint64_t);
    virtual void DiscoveryDataSubmitted(const cGcDiscoveryData *);
};

struct Session : AutoPooled<19>
{
    cGcDiscoveryStoreImpl<DefaultDiscoveryDataHashing, 19> mDiscoveryStore;
    cTkVector<cGcManagedDiscovery *> mManagedAvailableForSubmission;
    cTkDeque<cGcManagedDiscovery *> mManagedQueuedToSubmit;
    cTkVector<cGcManagedDiscovery *> mManagedSubmitted;
    cTkDeque<cGcAtlasSendReport> mReportsToSubmit;
};

struct OperationRetryTiming
{
    cTkPersonalRNG mRNG;
    cTkVector2 mDefaultDelayRange;
    cTkVector2 mMaximumDelayRange;
    cTkVector2 mCurrentDelayRange;
    float mfCurrentTimeout;
};

struct AtlasRequestContext
{
    uint64_t mu64UA;
    eDiscoveryType meType;
};

class cGcDiscoveryManager
{
  public:
    struct Data : AutoPooled<19>
    {
        cTkStackVector<IDiscoveryManagerEventHandler *, 4> mEventHandlers;
        Session *mpSession;
        cGcDiscoveryDataRing<40> mUndiscoveredRing;
        OperationRetryTiming mfRetryTimingDiscoverySubmission;
        OperationRetryTiming mfRetryTimingReports;
        unsigned int muAtlasApiUID;
        cTkVector<uint64_t> mRequestsInFlight;
        cTkVector<uint64_t> mRequestsNotify;
        cTkVector<std::shared_ptr<cGcAsyncOpsTempDiscovery>> mRequestsAsyncOps;
        robin_hood::detail::Table<
            true, 80, uint64_t, AtlasRequestContext, robin_hood::hash<uint64_t, void>, std::equal_to<uint64_t>>
            mAtlasHandleToContext;
        cTkVector<cGcDiscoverySearch *> mDiscoverySearches;
        DiscoverySearchContext mDiscoverySearchContext;
    };

    cGcRpcCallBase *NDMP;
    cGcDiscoveryManager::Data *mpData;
    cTkStackVector<IDiscoveryManagerEventHandler *, 4> mCachedHandlers;
};

SKYSCRAPER_END