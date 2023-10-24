#pragma once

#include <skyscraper.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/attachments/TkHandle.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/resources/TkResourceDescriptor.h>
#include <toolkit/simulation/components/TkAnimationComponent.h>

SKYSCRAPER_BEGIN

class cGcVehicleCockpit
{
	enum eCockpitLoadStates
	{
		ECockpitLoadState_Waiting,
		ECockpitLoadState_Loading,
		ECockpitLoadState_Loaded,
	};

	cGcVehicleCockpit::eCockpitLoadStates meCockpitLoadingState;
	cTkAttachmentPtr mpAttachment;
	TkHandle mRootNode;
	TkAudioObject mAudioObject;
	bool mbRequestEnter;
	bool mbRequestExit;
	bool mbRequestIsAnimated;
	cTkSmartResHandle mCockpitRes;
	const char* mpacCockpitFilename;
	cTkResourceDescriptor mCockpitDescriptor;
	TkHandle mCockpit;
	TkHandle mCockpitPoint;
	TkHandle mCockpitAnimNode;
	TkHandle mCockpitCameraLocator;
	TkHandle mCockpitPlayerLocator;
	TkHandle mCommunicatorHologramLocator;
	TkHandle mCanopyFadeNode;
	cTkAnimationComponent* mpCockpitAnim;
	cTkTimerTemplate<0> mCockpitTimer;
	cTkSmoothCD<float> mfCockpitRollAngle;
	cGcVehicleCockpit::eCockpitMode meCockpitMode;
	TkHandle maDamageLights[3];
	cTkHitCurve maDamageLightCurves[3];
	TkHandle maAlarmLights[1];
	float mfAlarmRate;
	bool mbAlarmActive;
	float mfAlarmActiveTime;
	cTkPhysRelVec3 mCockpitExitPoint;
	cTkMatrix34 mCockpitInterpOffsetInverse;
	cTkPhysRelMat34 mCockpitInterpStartFrame;
	TkID<128> mExitAnim;
	TkID<128> mDebugCockpitAnim;
	TkHandle mAtmosphereEffectNode;
	TkHandle mAtmosphereEffectTopNode;
	cTkMatrix34 mCockpitSpeedMeshStartFrame;
	TkHandle mCockpitSpeedMesh;
	std::vector<TkHandle, TkSTLAllocatorShim<TkHandle, 4, -1> > maStoppedVFXNodes;
	bool mbIsMoving;
	bool mbCockpitVisible;
	bool mbCockpitOverriddenToBeInvisible;
	bool mbFrostedGlass;
	eMechMeshType meActiveMechMeshType;
	TkHandle maMechInteriorNodes[2];
	TkHandle maMechDoorNodes[2];
	cTkAnimInstanceHandle mActiveAnim;
	cGcShootableComponent* mpShootable;
	cGcVehicleCockpit::eBobbleHeadLoadStates meBobbleHeadLoadState;
	TkHandle mBobbleHeadLocator;
	TkHandle mBobbleHeadNode;
	cTkSmartResHandle mBobbleHeadResource;
	float mfBobbleHeadFade;
	TkID<128> mBobbleHeadLinkedTechId;
	cTkVector3 mvBobbleHeadVelocity;
	cTkVector3 mvBobbeHeadRotation;
	cTkMatrix34 mBobbleHeadStartMatrix;
	TkHandle mVehicleFrontDecal;
	std::function<void __cdecl(void)> mOnAdded;
	std::function<void __cdecl(void)> mOnRemoved;
};

SKYSCRAPER_END