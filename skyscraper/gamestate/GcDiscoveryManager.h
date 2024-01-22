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
#include <toolkit/data/TkDocumentReader.h>
#include <toolkit/utilities/containers/TkDeque.h>
#include <toolkit/utilities/containers/TkStackContainer.h>
#include <toolkit/utilities/random/TkPersonalRNG.h>

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

class Session : AutoPooled<19>
{
  public:
    ITkDocumentReader::ReadResult LoadPersistent(ITkDocumentReader &lReader);
    void SavePersistent(ITkDocumentWriter &lWriter);
    bool RemoveRecord(cGcDiscoveryRecord *lpRecord);

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
    enum ExportSortOption;

    bool BeginRemoteQueryAllOnPlanet(const uint64_t &lu64Address, uint64_t);
    bool BeginRemoteQueryCategory(const uint64_t &lu64Address, eDiscoveryType leCategory, uint64_t);
    int BeginRemoteQueryExact(const cGcDiscoveryData &lDiscoveryData, uint64_t);
    void Clear();
    void Construct();
    cGcDiscoverySearch *CreateSearchInstance();
    GcDiscoverySearchConstraints::ConstraintBase *GenerateDiscoveryExport(
        cGcDiscoveryManager::ExportSortOption leExportSortOption, cTkVector<uint64_t> *lpOrphans,
        cTkVector<GcDiscoverySearchConstraints::ConstraintBase *> *lpapConstraints);
    int LookupDiscoveryWithStatus(
        const cGcDiscoveryData &lDiscoveryData, const cGcDiscoveryRecord *&lpDiscoveryRecordFound);
    void Prepare();
    bool SubmitCustomNameForDiscovery(const cGcDiscoveryRecord *lpRecord, cTkFixedString<128, char> *lpacCustomName);
    bool SubmitDiscoveryData(const cGcDiscoveryData &lDiscoveryData, bool *lpbLocallyNew);
    void UnRegisterForEvents(IDiscoveryManagerEventHandler *lpHandler);

    static void RPCNewDiscovery(
        cGcNetworkPlayer *lpPlayer, cGcDiscoveryData lDiscoveryData, int liTimestamp,
        cTkFixedString<128, char> lCustomName);

    enum ExportSortOption : uint8_t
    {
        NewestFirst,
        OldestFirst,
        OldestFirstWithPropagation,
    };

    struct Data : AutoPooled<19>
    {
        bool ConvertAndUpsertAtlasData(
            const cGcAtlasDiscovery &lAtlasData, cGcDiscoveryData &lDiscoveryData, bool lbClean);
        void DeleteSearchInstance(cGcDiscoverySearch *lpSearch);
        void HideAllDiscoveriesByBlockedUsers();
        void HideDiscoveryIfOwnerBlocked(const cGcDiscoveryRecord *lpRecord, const char *);
        bool IsDiscoveryOwnedByPlayer(const cGcDiscoveryRecord *lpRecord);
        ITkDocumentReader::ReadResult LoadPersistent(ITkDocumentReader &lReader);
        void NotifyDiscovery(
            uint64_t lHandle, const cTkMetaMessageWrapperTemplated<cGcAtlasShared> &lMetadata,
            uint64_t lu64RequestMetadataClassType);
        bool ProcessAtlasResponse(
            uint64_t lHandle, const cTkMetaMessageWrapperTemplated<cGcAtlasShared> &lMetadata,
            uint64_t lu64RequestMetadataClassType, AtlasRequestResult leResult);
        bool RetrieveOwnerDisplayName(const std::shared_ptr<cGcAsyncOpsTempDiscovery> &lpAsyncDiscovery);
        void RunSearches();
        /**
         * @fn SubbitDiscoveryReport (sic)
         */
        void SubbitDiscoveryReport(cGcDiscoveryRecord *lpDiscoveryRecord);
        bool SubmitDiscoveryData(const cGcDiscoveryData &lDiscoveryData, int liTimestamp, bool *lpbLocallyNew);
        bool SynchronousTrimDb(cGcDiscoveryManager *lpHost, uint32_t, uint32_t);
        void UpdateCheckReportQueue(float lfTimeStep);
        void UpdateCheckSubmissionQueue(float lfTimeStep);
        void UpdateProcessRequestsAsyncOps();
        void UpdateProcessRequestsInFlight();
        void UpdateProcessSubmitted();

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