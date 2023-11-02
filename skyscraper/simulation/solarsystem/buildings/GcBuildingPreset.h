#pragma once

#include <skyscraper.h>
#include <simulation/solarsystem/buildings/wfcbuildings/GcModuleSet.h>

SKYSCRAPER_BEGIN

class cGcBuildingPreset
{
    cGcModuleSet *mModuleSet;
    cGcMap *mpMap;
    cTkVector<cTkAABB> mBounds;
};

SKYSCRAPER_END