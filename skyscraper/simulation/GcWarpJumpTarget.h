#pragma once 

#include <skyscraper.h>
#include <simulation/galaxy/GcGalaxyTypes.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>

SKYSCRAPER_BEGIN

class cGcWarpJumpTarget
{
	cGcGalacticSolarSystemAddress mTargetSystem;
	cTkVector3 mTargetDirInMap;
	float mfDistanceToTarget;
	int miPortalPlanetIndex;
	bool mbWarpedFromAtlas;
};

SKYSCRAPER_END