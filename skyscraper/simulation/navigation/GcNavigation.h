#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <simulation/navigation/GcNavObstacleTracker.h>
#include <simulation/navigation/GcNavSteering.h>
#include <simulation/navigation/navigator/GcEnvironmentNavigator.h>
#include <simulation/navigation/GcNavigationResult.h>

SKYSCRAPER_BEGIN

class cGcNavigation
{
	cTkVector<cGcNavObstacleTracker*> mapObstacleTrackers;
	cGcEnvironmentNavigator* mpNavigator;
	cGcNavSteering* mpSteering;
	cGcNavigationQuery mNavQuery;
	cGcNavigationResult mNavResult;
	bool mbDebugBreak;
};

SKYSCRAPER_END