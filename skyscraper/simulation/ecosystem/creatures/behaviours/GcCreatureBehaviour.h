#pragma once

#include <skyscraper.h>

#include <toolkit/data/TkMetaData.h>

SKYSCRAPER_BEGIN

class cGcIdleAnimList
{
    TkID<128> mCurrentIdle;
    TkID<128> maIdles[10];
    int miNumIdles;
    TkID<128> maIdlesShuffled[10];
    int miNumIdlesShuffledRemaining;
    bool mbHasNonEatIdles;
};

SKYSCRAPER_END
