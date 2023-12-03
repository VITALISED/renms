#pragma once

#include <skyscraper.h>

#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cGcAsteroidLayout
{
  public:
    struct Data
    {
        float mfRotationY;
        float mfRotationX;
        float mfSize;
        float mfRandom;
    };

    cTkVector<cTkVector3> mPositions;
    cTkVector<cGcAsteroidLayout::Data> mData;
};

SKYSCRAPER_END