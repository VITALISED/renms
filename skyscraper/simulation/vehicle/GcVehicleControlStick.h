#pragma once

#include <skyscraper.h>
#include <toolkit/simulation/physics/TkPhysicsComponent.h>
#include <metadata/source/simulation/player/gchand.meta.h>

SKYSCRAPER_BEGIN

class cGcVehicleControlStick
{
	enum Type
	{
		Stick,
		Throttle,
	};

	cGcVehicleControlStick::Type meStickType;
	eHand meStickHand;
	cTkVector2 mStickValue;
	cTkVector2 mStickMinValue;
	cTkVector2 mStickMaxValue;
	cTkVector2 mMovementSpeedLimit;
	TkHandle mStickBaseNode;
	cTkPhysicsComponent* mpStickBasePhysics;
	TkHandle mStickHandle;
	cTkMatrix34 mStickOriginalTransform;
	cTkMatrix34 mStickGrabOffset;
	float mfTimeSinceStickHeld;
	float mfStickHoldTime;
	cTkVector3 mStickBasePos;
	bool mbStickGrabbed;
	bool mbMoveStickToNeutralPosition;
};

SKYSCRAPER_END