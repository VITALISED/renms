#pragma once

#include <skyscraper.h>

//ideally we want renms to be cross plat, if anyone knows what this struct might be on other platforms that'd be great

SKYSCRAPER_BEGIN

class cTkCSMutex
{
    _RTL_CRITICAL_SECTION mMutex;
};

SKYSCRAPER_END