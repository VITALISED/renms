#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class cTkNGuiElementID
{
    __int64 miCounter;
    unsigned __int64 miBase;
    int miFrameRenderTracker;
    int miPerFrameUseCount;
};

SKYSCRAPER_END