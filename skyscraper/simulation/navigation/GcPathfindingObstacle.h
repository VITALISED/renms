#pragma once

#include <skyscraper.h>
#include <toolkit/maths/geometry/TkPhysRelVec3.h>
#include <toolkit/attachments/TkHandle.h>

SKYSCRAPER_BEGIN

class cGcPathfindingObstacle
{
	cTkPhysRelVec3 mvPos;
	float mfRadius;
	TkHandle mNode;
};

SKYSCRAPER_END