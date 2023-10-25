#pragma once

#include <skyscraper.h>
#include <simulation/navigation/GcNavigationConfig.h>
#include <simulation/navigation/GcNavTarget.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>

SKYSCRAPER_BEGIN

class cGcNavigationQuery
{
	cGcNavigationConfig mConfig;
	cTkPhysRelMat34 mNavMatrix;
	bool mbUseDebugTarget;
	bool mbDebugForceInvalid;
	cGcNavTarget mNavTarget;
	cGcNavTarget mDebugNavTargetOverride;
};

SKYSCRAPER_END