#pragma once

#include <skyscraper.h>

#include <toolkit/maths/numeric/generic/TkVector3Generic.h>

#include <toolkit/voxel/generator/tkvoxelgeneratordata.meta.h>

SKYSCRAPER_BEGIN

class cTkRegionMapBase
{
    virtual int GetScaleX();
    virtual int GetScaleY();
    virtual int GetScaleZ();
    virtual cTkVector3 *GetCentre(cTkVector3 *result);
};

template <int liUnk1, int liUnk2, int liUnk3, int liUnk4, typename T>
class cTkRegionMap : public cTkRegionMapBase
{
    int miScaleX;
    int miScaleY;
    int miScaleZ;
    T mRegion;
    cTkVoxelGeneratorData *mpGeneratorData;
};

SKYSCRAPER_END