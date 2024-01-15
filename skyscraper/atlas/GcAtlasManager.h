/**
 * @file GcAtlasManager.h
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

#include <atlas/broker/GcAtlasBroker.h>
#include <atlas/transport/GcAtlasTransport.h>
#include <toolkit/system/thread/TkLockFreeQueue.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/string/TkString.h>

SKYSCRAPER_BEGIN

namespace AtlasConnectionState
{

typedef int Enum;

}

/**
 * @brief "Atlas" structures and calls refer to the NMS discovery servers. It's effectively a high level HTTP wrapper.
 * The Atlas Manager is of course, the high level controller for transport and broker tasks and dispatches.
 */
class cGcAtlasManager
{
  public:
    void Construct();
    void Destruct();
    void Update();
    // TODO: Nanovg crap
    void RenderActivityIcon(const cTkVector2 &lCenterPos, void *lpContext, bool lfScale, float lCenterPos_0);
    cGcAtlasBroker::State::Enum GetConnectionState();
    cGcAtlasBroker::State::Enum GetDisplayConnectionState();
    uint64_t InternalEnqueueRequest(
        const cTkMetaMessageWrapperTemplated<void> &lRequestMetadata, float lRequestTimeoutSeconds,
        const TkID<128> &lpacDebugTag);
    bool CancelRequest(uint64_t lHandle);
    bool PollForRequestCompletion(uint64_t lHandle);
    uint64_t FetchRequestResult(
        uint64_t lHandle, cTkMetaMessageWrapperTemplated<cGcAtlasShared> &lMetadataResult,
        uint64_t &lu64RequestMetadataClassType, TkID<128> *lpDebugTagOut);
    bool FreeRequestResult(uint64_t lHandle);
    cGcAtlasCommunityData *GetAtlasCommunityData();
    void DoThreadedUpdate(void *lpData);
    bool IsConnectionDown();

    template <typename T>
    uint64_t EnqueueRequest(const T &lMetaType, float lRequestTimeoutSeconds, const TkID<128> &lpacDebugTag);

    struct Data
    {
        void UpdateInternal();

        float mfLastUpdateTime;
        cGcAtlasTransport *mpActiveTransport;
        cGcAtlasBroker *mpActiveBroker;
        bool mbAtlasNetworkingStarted;
        std::atomic<uint64_t> muCurrentHandle;
        cTkInplaceLockFreeQueue<AtlasRequestTask *, 8> mIncomingRequestsQueue;
        cTkInplaceLockFreeQueue<AtlasResponseTask *, 8> mOutgoingResultsQueue;
        cTkInplaceLockFreeQueue<uint64_t, 8> mCancellationQueue;
        cTkVector<AtlasRequestTask *> mRequestTasks;
        cTkVector<AtlasResponseTask *> mResponseTasks;
    };

    cGcAtlasManager::Data *mpData;
    uint64_t mu64OverlayFirstTimeValue;
    uint64_t mu64OverlayLastTimeValue;
    float mfOverlayVisibilityTimeout;
    float mfOverlayAlpha;
    AtlasConnectionState::Enum meOverlayLastStateSeen;
    uint32_t miLastSeenBrokerReadyCounter;
    int miCurrentErrorCount;
    cTkFixedString<64, char> macDevAccessKey;
    cTkFixedString<64, char> macMagicAccessKey;
    void *mShutdownMutex;
    volatile bool mbThreadShutdown;
    volatile bool mbThreadRunning;
};

SKYSCRAPER_END