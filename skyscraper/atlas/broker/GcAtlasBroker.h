/**
 * @file GcAtlasBroker.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
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

#include <atlas/broker/GcAtlasCommunityData.h>
#include <atlas/broker/recv/GcAtlasRecvActiveFeaturedBasesQuery.h>
#include <atlas/broker/recv/GcAtlasRecvBaseImages.h>
#include <atlas/broker/recv/GcAtlasRecvBaseList.h>
#include <atlas/broker/recv/GcAtlasRecvBaseQueryList.h>
#include <atlas/broker/recv/GcAtlasRecvBasic.h>
#include <atlas/broker/recv/GcAtlasRecvBlob.h>
#include <atlas/broker/recv/GcAtlasRecvDiscoveryExact.h>
#include <atlas/broker/recv/GcAtlasRecvDiscoveryList.h>
#include <atlas/broker/recv/GcAtlasRecvFeaturedBasesQueryList.h>
#include <atlas/broker/recv/GcAtlasRecvMonumentList.h>
#include <atlas/broker/recv/GcAtlasRecvSettlementList.h>
#include <atlas/broker/recv/GcAtlasRecvTotalContribution.h>
#include <atlas/broker/recv/GcAtlasRecvVoxel.h>
#include <atlas/broker/requests/GcAtlasSendChangeFeaturedBasesEnv.h>
#include <atlas/broker/requests/GcAtlasSendMarkFeaturedBase.h>
#include <atlas/broker/requests/GcAtlasSendMarkFeaturedBaseWithImage.h>
#include <atlas/broker/requests/GcAtlasSendQueryActiveFeaturedBases.h>
#include <atlas/broker/requests/GcAtlasSendQueryBaseImages.h>
#include <atlas/broker/requests/GcAtlasSendQueryBases.h>
#include <atlas/broker/requests/GcAtlasSendQueryFeaturedBases.h>
#include <atlas/broker/requests/GcAtlasSendQuerySeasonData.h>
#include <atlas/broker/requests/GcAtlasSendRemoveFeaturedBases.h>
#include <atlas/broker/requests/GcAtlasSendReport.h>
#include <atlas/broker/requests/GcAtlasSendReportBase.h>
#include <atlas/broker/requests/GcAtlasSendRequestBases.h>
#include <atlas/broker/requests/GcAtlasSendRequestBlob.h>
#include <atlas/broker/requests/GcAtlasSendRequestDiscoveryAllOnPlanet.h>
#include <atlas/broker/requests/GcAtlasSendRequestDiscoveryCategory.h>
#include <atlas/broker/requests/GcAtlasSendRequestDiscoveryExact.h>
#include <atlas/broker/requests/GcAtlasSendRequestMonument.h>
#include <atlas/broker/requests/GcAtlasSendRequestSettlements.h>
#include <atlas/broker/requests/GcAtlasSendRequestTotalContribution.h>
#include <atlas/broker/requests/GcAtlasSendRequestVoxel.h>
#include <atlas/broker/requests/GcAtlasSendSubmitBaseWithImage.h>
#include <atlas/broker/requests/GcAtlasSendSubmitContributionActual.h>
#include <atlas/broker/requests/GcAtlasSendSubmitDiscoveryExact.h>
#include <atlas/broker/requests/GcAtlasSendSubmitMessage.h>
#include <atlas/broker/requests/GcAtlasSendSubmitMonument.h>
#include <atlas/broker/requests/GcAtlasSendSubmitSeasonStageCompleted.h>
#include <atlas/broker/requests/GcAtlasSendSubmitSettlement.h>
#include <atlas/transport/GcAtlasTransport.h>
#include <toolkit/core/types/TkID.h>
#include <toolkit/system/memory/pools/TkMemoryPool.h>
#include <toolkit/utilities/containers/TkMetaMessageMap.h>

SKYSCRAPER_BEGIN

enum AtlasRequestResult
{
    _NotReady,
    Success,
    Failed_ManualCancellation,
    Failed_TimedOut,
    Failed_InvalidDataReceived,
    Failed_CompletionError,
    Failed_BadRequest,
    Failed_RateLimited,
};

class cGcIBrokerData : public AutoPooled<5>
{
  public:
    virtual ~cGcIBrokerData();
};

class AtlasTaskCommon
{
  public:
    virtual ~AtlasTaskCommon();

    cGcIBrokerData *mpBrokerData;
    uint64_t mHandle;
    cTkMetaMessageWrapperTemplated<cGcAtlasShared> mMetadata;
    TkID<128> mDebugTag;
};

class AtlasRequestTask : public AtlasTaskCommon
{
  public:
    float mTTL;
};

class AtlasResponseTask : public AtlasTaskCommon
{
  public:
    AtlasRequestResult mResult;
    uint64_t mRequestTypeMetadataHash;
};

class cGcAtlasBroker
{
  public:
    struct State
    {
        enum Enum
        {
            Invalid,
            Disconnected,
            Authenticate,
            Ready,
            __EnumTerminator,
            Unspecified,
        };
    };

    enum CompletionResult
    {
        Invalid,
        Disconnected,
        Authenticate,
        Ready,
        __EnumTerminator,
        Unspecified,
    };

    cGcAtlasTransport *mpTransport;
    cGcAtlasBroker::State::Enum meState;

    cGcAtlasBroker::CompletionResult Complete(
        const AtlasRequestTask *lpRequestTask, AtlasResponseTask *lpResponseTask,
        const bool lbShouldRunDoCompletionRoutine);

    virtual ~cGcAtlasBroker();
    virtual void Reset();
    virtual const char *GetName();
    virtual bool RequiresTransport();
    virtual unsigned int GetReadyStateCounter();
    virtual bool Construct(cGcAtlasTransport *);
    virtual void Destruct();
    virtual void Update(float);
    virtual void UpdateThreadStart();
    virtual void UpdateThreadEnd();
    virtual AtlasRequestResult Service(AtlasTaskCommon *);
    virtual void Abandon(AtlasTaskCommon *);
    virtual void DeleteTaskData(cGcIBrokerData *);
    virtual bool GetMessagesEnabled();
    virtual const char *GetOpenIdToken();
    virtual cGcAtlasCommunityData *GetAtlasCommunityData();
    virtual cGcURL *GetAtlasBaseImagesRoute();
    virtual cGcURL *GetAtlasFeaturedBaseImagesRoute();
    virtual cGcURL *GetAtlasSeasonDataRoute();
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendRequestSettlements *, cGcAtlasRecvSettlementList *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendSubmitSettlement *, cGcAtlasRecvBasic *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendSubmitSeasonStageCompleted *, cGcAtlasRecvBasic *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendQuerySeasonData *, cGcAtlasRecvBasic *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendRequestTotalContribution *, cGcAtlasRecvTotalContribution *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendSubmitContributionActual *, cGcAtlasRecvBasic *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendRequestMonument *, cGcAtlasRecvMonumentList *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendSubmitMonument *, cGcAtlasRecvBasic *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendRequestBlob *, cGcAtlasRecvBlob *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendRequestVoxel *, cGcAtlasRecvVoxel *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendReportBase *, cGcAtlasRecvBasic *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendReport *, cGcAtlasRecvBasic *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendSubmitBaseWithImage *, cGcAtlasRecvBasic *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendSubmitBase *, cGcAtlasRecvBasic *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendSubmitMessage *, cGcAtlasRecvBasic *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendSubmitDiscoveryExact *, cGcAtlasRecvBasic *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendQueryBaseImages *, cGcAtlasRecvBaseImages *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendChangeFeaturedBasesEnv *, cGcAtlasRecvBasic *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendRemoveFeaturedBases *, cGcAtlasRecvBasic *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendQueryActiveFeaturedBases *, cGcAtlasRecvActiveFeaturedBasesQuery *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendMarkFeaturedBaseWithImage *, cGcAtlasRecvBasic *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendMarkFeaturedBase *, cGcAtlasRecvBasic *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendQueryFeaturedBases *, cGcAtlasRecvFeaturedBasesQueryList *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendQueryBases *, cGcAtlasRecvBaseQueryList *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendRequestBases *, cGcAtlasRecvBaseList *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendRequestDiscoveryAllOnPlanet *, cGcAtlasRecvDiscoveryList *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendRequestDiscoveryCategory *, cGcAtlasRecvDiscoveryList *);
    virtual cGcAtlasBroker::CompletionResult DoCompletion(
        cGcIBrokerData *, const cGcAtlasSendRequestDiscoveryExact *, cGcAtlasRecvDiscoveryExact *);
};

SKYSCRAPER_END