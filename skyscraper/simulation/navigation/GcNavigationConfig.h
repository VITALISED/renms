#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class cGcNavigationConfig
{
	float mfMinUpdatePeriod;
	float mfNavRadius;
	float mfHeight;
	float mfMaxSpeed;
	float mfMinObstacleSize;
	unsigned __int8 muPreferredLOD;
	unsigned __int16 muAllowedRegionTypeMask;
	bool mbNoPhysModeEnabled;
};

SKYSCRAPER_END