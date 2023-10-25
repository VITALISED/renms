#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class cGcGalacticVoxelCoordinate
{
    __int16 mX;
    __int16 mZ;
    __int16 mY;
    bool mbValid;
};

class cGcGalacticSolarSystemAddress
{
    cGcGalacticVoxelCoordinate mVoxelCoordinate;
    unsigned __int16 mSolarIndex;
    unsigned __int16 mIteration;
};

SKYSCRAPER_END