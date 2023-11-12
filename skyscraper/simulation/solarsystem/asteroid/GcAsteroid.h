#pragma once

#include <skyscraper.h>

#include <simulation/environment/regiondata/GcRegionAsteroid.h>
#include <toolkit/voxel/TkVoxelVertexDefinition.h>
#include <toolkit/voxel/manager/TkRegionMap.h>

SKYSCRAPER_BEGIN

class cGcAsteroid
{
    cTkVoxelArray mRegionData;
    cTkRegionMap<16, 16, 32, -1, cGcRegionAsteroid> mRegionMap;
    float mfCachedScale;
    float mfCachedFade;
};

SKYSCRAPER_END