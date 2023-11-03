#pragma once

#include <skyscraper.h>
#include <simulation/environment/regiondecorators/GcRegionDecoratorObjects.h>
#include <simulation/environment/regiondecorators/GcRegionDecoratorPhysics.h>
#include <simulation/environment/regiondata/terrain/GcRegionTerrain.h>

SKYSCRAPER_BEGIN

class cGcRegionTerrainVeryFar : public cGcRegionTerrain
{
    cGcRegionDecoratorPhysics mInstancePhysics;
    cGcRegionDecoratorObjects mFoliage;
};

SKYSCRAPER_END