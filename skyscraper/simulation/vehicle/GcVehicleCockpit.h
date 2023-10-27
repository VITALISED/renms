/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <skyscraper.h>
#include <simulation/projectiles/GcShootableComponent.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/attachments/TkHandle.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/resources/TkResourceDescriptor.h>
#include <toolkit/simulation/components/TkAnimationComponent.h>
#include <toolkit/system/timer/TkTimer.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>
#include <toolkit/maths/numeric/TkSmoothCD.h>
#include <toolkit/animation/TkHitCurve.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <metadata/simulation/vehicles/gcmechmeshtype.meta.h>

SKYSCRAPER_BEGIN

class cGcVehicleCockpit
{
	enum eCockpitLoadStates
	{
		ECockpitLoadState_Waiting,
		ECockpitLoadState_Loading,
		ECockpitLoadState_Loaded,
	};

	enum eCockpitMode
	{
		ECockpit_None,
		ECockpit_EnterInterp,
		ECockpit_Enter,
		ECockpit_Inside,
		ECockpit_Exit,
		ECockpit_ExitFinal,
	};

	enum eBobbleHeadLoadStates
	{
		EBoobleHeadLoadState_Start,
		EBoobleHeadLoadState_Loading,
		EBoobleHeadLoadState_Update,
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
	cTkVector<TkHandle> maStoppedVFXNodes;
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