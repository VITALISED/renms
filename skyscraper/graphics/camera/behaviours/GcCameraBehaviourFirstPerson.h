#pragma once

#include <skyscraper.h>
#include <graphics/camera/behaviours/GcGameCamera.h>
#include <metadata/source/simulation/player/gczoomdata.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayer;

class cGcCameraBehaviourFirstPerson : cGcGameCamera
{
	cGcPlayer* mpPlayer;
	cTkPhysRelMat34 mPrevMatrix;
	cGcPlayerCameraLook mCameraLook;
	cTkMatrix34 mMotionMatrix;
	float mfTime;
	bool mbInstantSwitchFov;
	eZoomType meZoomLevel;
	float mfFovSpringSpeed;
	cTkSmoothCD<float> mfHeadRunTuck;
	float mfBobFactor;
	float mfBobStrength;
	float mfBobAmount;
	float mfPostVehicleExitTimer;
	bool mbInVehicle;
	bool mbShipFreeLook;
	cTkSmoothCD<float> mfFovFixedDist;
	TkHandle mCockpitNode;
};

SKYSCRAPER_END