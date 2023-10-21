#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class cTkStopwatch
{
    unsigned __int64 miDuration;
    unsigned __int64 miStartTime;
    bool mbRunning;
};

SKYSCRAPER_END