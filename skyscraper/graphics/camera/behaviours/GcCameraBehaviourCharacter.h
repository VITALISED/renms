#pragma once

#include <skyscraper.h>
#include <simulation/player/GcPlayer.h>
#include <toolkit/graphics/camera/behaviours/TkCameraBehaviour.h>
#include <toolkit/simulation/physics/havok/TkHavokDynamicCharacterController.h>

SKYSCRAPER_BEGIN

class cGcCameraBehaviourCharacter : public cTkCameraBehaviour
{
	cGcPlayer* mpPlayer;
	cTkVector3 mCamLookOffset;
	cTkVector2 mDeflectOffset;
	float mfCamOffsetAngle;
	float mfCamOffsetLength;
	float mfIdleTimer;
	float mfHeight;
	bool mbHadALook;
	cTkHavokCharacterController* mpController;
};

SKYSCRAPER_END