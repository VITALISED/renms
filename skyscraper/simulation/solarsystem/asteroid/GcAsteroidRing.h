#pragma once

#include <skyscraper.h>

#include <toolkit/maths/geometry/TkSphere.h>

SKYSCRAPER_BEGIN

class cGcAsteroidRing
{
    cTkSphere mInnerSphere;
    cTkSphere mOuterSphere;
    cTkVector3 mRingUp;
    float mRingWidth;
};

SKYSCRAPER_END