#pragma once

#include <skyscraper.h>
#include <toolkit/maths/geometry/TkPhysRelVec3.h>

SKYSCRAPER_BEGIN

class cGcNavTarget
{
	enum eNavTargetType
	{
		ENavTargetType_Invalid,
		ENavTargetType_Position,
		ENavTargetType_PositionWithOrientation,
		ENavTargetType_Direction,
	};

	cGcNavTarget::eNavTargetType meTargetType;
	cTkPhysRelVec3 mvTargetPos;
	cTkVector3 mvTargetDir;
	float mfTolerance;
};

SKYSCRAPER_END