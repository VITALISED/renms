#pragma once

#include <skyscraper.h>
#include <gamestate/GcUserSettings.h>
#include <simulation/player/GcPlayerController.h>
#include <toolkit/maths/numeric/TkSmoothCD.h>
#include <metadata/simulation/player/gcplayerstickdata.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerStick
{
	cGcPlayerController* mpController;
	cGcPlayerStickData* mpData;
	int miXAxis;
	int miYAxis;
	cTkVector2 mBaseStick;
	cTkSmoothCD<cTkVector2> mLastStickDir;
	cTkVector3 mLastInput;
	float mfAcceleration;
	float mfAccelerationTimer;
	cGcUserSettings::Sensitivity meSensitivityType;
	cTkVector2 mMousePos;
	float mfAutoAimStickyFactor;
	cTkColour mNormalRateColour;
	cTkColour mAcceleratedRateColour;
	cTkVector2 mDebugScreenCircleCentre;
	float mfDebugScreenCircleRadius;
	float mfDebugScreenCircleRadiusInner;
	cTkVector2 mGyroChanges;
	int miSmoothingIndex;
	cTkVector2 maSmoothingGyroBuffer[16];
	float mfSpecialVehicleMouseRecentreTimer;
};


SKYSCRAPER_END