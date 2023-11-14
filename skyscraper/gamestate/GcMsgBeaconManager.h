#pragma once

#include <skyscraper.h>

#include <simulation/environment/scanning/GcMarkerPoint.h>
#include <system/GcAsyncOpsTempBase.h>
#include <toolkit/system/memory/pools/TkMemoryPool.h>

#include <atlas/gcatlasdiscovery.meta.h>

SKYSCRAPER_BEGIN

class cGcMsgBeacon : AutoPooled<5>
{
    typedef cGcAsyncOpsTempBase::ProfanityState ProfanityState;
    typedef cGcAsyncOpsTempBase::ProfanityState DisplayNameState;
    typedef cGcAsyncOpsTempBase::ProfanityState PermissionState;

    enum UploadStatus
    {
        eFailed,
        eSucceeded,
        eUnknown,
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

SKYSCRAPER_END