#pragma once

#include <skyscraper.h>
#include <simulation/components/scanning/GcScanEffectComponent.h>
#include <simulation/projectiles/GcBeamEffect.h>
#include <simulation/EffectInstance.h>
#include <toolkit/resources/TkSmartResHandle.h>
#include <toolkit/attachments/TkHandle.h>
#include <toolkit/maths/geometry/TkPlane.h>

SKYSCRAPER_BEGIN

class cGcWeapon;

enum eEditPlaneState
{
	EEditPlaneState_Disabled,
	EEditPlaneState_LockedOnPlane,
	EEditPlaneState_LockedInFrontOfPlane,
};

enum eTerrainEditShape
{
	ETerrainEditShape_Sphere,
	ETerrainEditShape_Cube,
	ETerrainEditShape_Num,
};

class cGcTerrainEditorBeam
{
public:
	enum eEditMode
	{
		EEditMode_SubtractiveMode,
		EEditMode_AdditiveMode,
		EEditMode_FlatteningMode,
		EEditMode_UndoMode,
		EEditMode_NumTypes,
	};

	cGcWeapon* mpOwnerWeapon;
	cTkSmartResHandle mHologramResources[3];
	TkHandle mHologramNodes[3];
	cGcScanEffectComponent* mpHologramEffects[3];
	cTkSmartResHandle mPlaneHologramResource;
	TkHandle mPlaneHologramNode;
	int miCurrentHologramIndex;
	TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mPlaneMaterial;
	cTkSmartResHandle mMuzzleEffectResources[4];
	float mfHologramLastInactiveTime;
	float mfHologramLastActiveTime;
	cGcScanEffectData mEditScanData;
	cGcBeamEffect mBeam;
	cGcBeamEffect mBeamCore;
	EffectInstance mTerrainEditorEffectHandle;
	EffectInstance mImpactEffectHandle;
	TkHandle mMuzzleEffects[4];
	cTkVector3 mLastEditAddLocation;
	bool mbLastEditWasAdd;
	bool mbActive;
	bool mbPrepared;
	TkAudioObject mAudioObject;
	float mfFiringTime;
	float mfLastFireTime;
	float mfLastEditTime;
	cTkPlane mEditPlane;
	eEditPlaneState meEditPlaneState;
	int miCurrentSizeIndex;
	eTerrainEditShape meCurrentShape;
	cTkVector3 mCurrentEditPosition;
	cTkVector3 mLastEditPosition;
	cTkVector3 mLastApplyPosition;
	bool mbRaycastHit;
	bool mbRaycastHitTerrain;
	bool mbPositionOverlapsObject;
	float mfPositionRaycastOffset;
	float mfCurrentEditPositionDistance;
	cGcTerrainEditorBeam::eEditMode meEditMode;
	float mfModeSwitchTime;
	bool mbInterpolationTrailLost;
	bool mbDisableLastEditHologram;
	bool mbShowNotificationMessage;
	float mfLastSizeChangeTime;
	TkHandle mLight;
};

SKYSCRAPER_END