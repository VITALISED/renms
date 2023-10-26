#pragma once

#include <skyscraper.h>
#include <simulation/solarsystem/buildings/GcBuilding.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cGcBuildingList
{
    cGcBuilding *mpaBuildingArray;
    cTkVector<cGcBuilding *> mBuildingsByDistance;
    cTkVector<cGcBuilding *> mBuildingsByID;
    cTkVector<cGcBuilding *> maOutposts;
    cTkVector3 mComparisonPosition;
};

SKYSCRAPER_END