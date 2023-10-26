#pragma once

#include <skyscraper.h>
#include <metadata/source/graphics/camera/shake/gccamerashakedata.meta.h>

SKYSCRAPER_BEGIN

class cGcCameraShake
{
	cGcCameraShakeData* mpData;
	float mfStrength;
	float mfStartTime;
	cTkMatrix34 mBase;
};

SKYSCRAPER_END