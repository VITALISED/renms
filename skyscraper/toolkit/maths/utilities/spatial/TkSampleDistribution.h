#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class cTkMcQmcLFSR
{
    const unsigned int muiPeriod;
    std::array<unsigned int,32> mauiF;
};

class cTkMcQmcLFSRStore
{
    std::array<cTkMcQmcLFSR *,3> mSamplers;
};


SKYSCRAPER_END