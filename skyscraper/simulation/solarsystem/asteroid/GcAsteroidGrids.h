#pragma once

#include <skyscraper.h>

#include <simulation/solarsystem/asteroid/GcAsteroid.h>
#include <simulation/solarsystem/asteroid/GcAsteroidRing.h>
#include <toolkit/maths/geometry/TkSphere.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <toolkit/utilities/TkArray.h>
#include <toolkit/utilities/containers/TkClassPool.h>

#include <simulation/gcasteroidgenerationdata.meta.h>

SKYSCRAPER_BEGIN

template <int liVal>
class cGcAsteroidGrid
{
    VFT<5> *__vftable;
    bool mbVertical;
    cTkClassPool<cTkSphere, 32> *mpInvalidAreas;
    cTkClassPool<cGcAsteroidRing, 32> *mpValidAreas;
    cTkVector3 mPlayerPosition;
    cTkVector3 mPlayerDirection;
    float mfCullDistance;
    float mbUseCulling;
    unsigned __int64 mu64UniqueId;
    int miX;
    int miY;
    int miZ;
    int miMaxNumCalcsPerUpdate;
    int miLastNumCalcs;
    cTkBitArray<unsigned __int64, 5 * liVal> mxGridGenerated;
    bool mbFirstGeneration;
    cGcAsteroidGenerationData mAsteroidGenerationData;
};

template <int liVal>
class cGcVoxelAsteroidGrid : public cGcAsteroidGrid
{
    std::array<float, 5 * liVal> mafActiveTimes;
    std::array<cGcAsteroid, 5 * liVal> maData;
    cTkBitArray<unsigned __int64, 5 * liVal> mxVoxelGenerated;
    cTkBitArray<unsigned __int64, 5 * liVal> mxValidity;
};

SKYSCRAPER_END