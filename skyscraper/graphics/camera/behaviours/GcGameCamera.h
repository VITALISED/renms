#pragma once

#include <skyscraper.h>
#include <simulation/player/controllers/GcPlayerStick.h>
#include <toolkit/graphics/camera/behaviours/TkCameraBehaviour.h>

SKYSCRAPER_BEGIN

struct  cGcPlayerCameraLook
{
	cGcPlayerStick mStick;
	cTkMatrix34 mLookMatrix;
	cTkSmoothCD<float> mfLookTurn;
	cTkSmoothCD<float> mfLookPitch;
};

class cGcGameCamera : public cTkCameraBehaviour
{ };

SKYSCRAPER_END