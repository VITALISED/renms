#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class cTkTimeManager
{
  public:
    struct UTCFractional
    {
        uint64_t muSeconds;
        float mfFractional;
    };
};

SKYSCRAPER_END