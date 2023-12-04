#pragma once

#include <skyscraper.h>

#include <atlas/broker/GcAtlasBroker.h>
#include <atlas/transport/GcAtlasTransport.h>
#include <toolkit/system/thread/TkLockFreeQueue.h>
#include <toolkit/utilities/TkString.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

namespace AtlasConnectionState
{

typedef int Enum;

}

class cGcAtlasManager
{
  public:
    struct Data
    {
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