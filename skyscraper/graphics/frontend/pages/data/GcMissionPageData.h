#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class cGcMissionPageData
{
    bool mbReset;
    int miCurrentSecMissionPage;
    float mfTimeSinceLastTransition;
    bool mbAutoScrollDone;
};

SKYSCRAPER_END