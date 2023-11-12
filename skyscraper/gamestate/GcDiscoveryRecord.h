#pragma once

#include <skyscraper.h>

#include <gamestate/GcDiscoveryCommon.h>
#include <toolkit/system/memory/pools/TkMemoryPool.h>

#include <reality/gcdiscoveryowner.meta.h>

SKYSCRAPER_BEGIN

class cGcDiscoveryMetadata : AutoPooled<19>
{
    cTkFixedString<127, char> mCustomName;
    bool mbHasCustomName;
};

class cGcDiscoveryRecord : AutoPooled<19>
{
    cGcDiscoveryData mData;
    cGcDiscoveryOwner mOwnership;
    cGcDiscoveryMetadata mMetadata;
    cTkFixedString<64, char> mRID;
    cTkFixedString<3, char> mPTK;
    unsigned __int8 mFlags;
};

struct cGcDiscoveryExport : AutoPooled<19>
{
    struct Planet
    {
        const cGcDiscoveryRecord *mpData;
        unsigned __int64 mu64UA;
        int miSortTimestamp;
        cTkVector<cGcDiscoveryRecord const *> mDiscoveries;
    };

    struct SolarSystem
    {
        const cGcDiscoveryRecord *mpData;
        unsigned __int64 mu64UA;
        int miSortTimestamp;
        cTkVector<cGcDiscoveryExport::Planet> mPlanets;
    };

    cTkVector<cGcDiscoveryExport::SolarSystem> mSolarSystems;
};

SKYSCRAPER_END