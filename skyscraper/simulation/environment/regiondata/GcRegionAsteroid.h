#pragma once

#include <skyscraper.h>

#include <simulation/environment/regiondata/GcRegion.h>
#include <simulation/environment/regiondecorators/GcRegionDecoratorPhysics.h>
#include <skyscraper/simulation/VoxelType.h>
#include <toolkit/maths/geometry/TkAABB.h>
#include <toolkit/voxel/terrain/TkTerrainVertex.h>

SKYSCRAPER_BEGIN

class cGcRegionAsteroid : public cGcRegionBase
{
    cTkVector3 mOffset;
    cTkAABB mBoundingBox;
    cGcRegionDecoratorPhysics mTerrainPhysics;
    cTkTerrainVertexData *mpMappedStreamTerrain;
    cTkSeed mSeed;
    eVoxelType meMineableResourceType;
};

SKYSCRAPER_END