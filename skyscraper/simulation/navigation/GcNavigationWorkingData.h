#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/containers/TkStackVector.h>
#include <simulation/navigation/GcPathfindingObstacle.h>

SKYSCRAPER_BEGIN

class cGcNavigationWorkingData
{
	cTkStackVector<cGcPathfindingObstacle> maObstacleList;
	cTkPhysRelVec3 mvCurrentSubTarget;
	cTkVector3 mvCurrentDir;
	cTkVector<cTkPhysRelVec3> mavPath;
};

SKYSCRAPER_END