#pragma once

#include <skyscraper.h>
#include <toolkit/maths/geometry/TkPhysRelVec3.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cGcNavigationResult
{
	enum eNavResultType
	{
		ENavResultType_Invalid,
		ENavResultType_Move,
		ENavResultType_AtTarget,
	};

	float mfResultTime;
	cGcNavigationResult::eNavResultType meResultType;
	cTkVector3 mvDirection;
	cTkVector<cTkPhysRelVec3> mavPath;
	cTkPhysRelVec3 mvCurrentTarget;
};

SKYSCRAPER_END