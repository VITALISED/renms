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
#include <simulation/GcCharacterInterface.h>
#include <simulation/player/GcCharacterSuitAudio.h>
#include <simulation/EffectInstance.h>
#include <simulation/particles/GcJetPackEffect.h>
#include <simulation/components/player/GcPlayerFullBodyIkComponent.h>
#include <networking/components/GcNetworkInterpolationComponent.h>
#include <toolkit/maths/numeric/TkSmoothCD.h>
#include <toolkit/networking/TkReplicatedVariable.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <toolkit/graphics/utilities/StencilModes.h>
#include <toolkit/animation/engine/TkNodeAnimationControllerEngine.h>
#include <toolkit/simulation/components/TkAnimationComponent.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/random/TkPersonalRNG.h>
#include <metadata/source/simulation/components/utils/gcplayercharactercomponentdata.meta.h>
#include <metadata/source/simulation/player/gcplayercharacterstatetype.meta.h>
#include <metadata/source/simulation/player/gcplayercharacterstatetable.meta.h>
#include <metadata/source/simulation/character/gcplayercontrolstate.meta.h>
#include <metadata/source/animation/gcthirdpersonanimparams.meta.h>

SKYSCRAPER_BEGIN

typedef StencilModes::List eCamouflageState;

enum AnimationTransitionType
{
	NoTransition,
	TransitionInto,
	Intermediate,
};


class cGcPlayerBackpackBars
{
	TkHandle mThirdPersonNode;
	TkHandle mBackpackMeshNode;
	cTkSmartResHandle mBackpackLifeSupportMaterial;
	cTkSmartResHandle mBackpackHazardProtectionMaterial;
	cGcCharacterInterface* mpCharacterInterface;
	float mfBackpackFlashTimer;
	float mfBackpackLifeSupportBarValue;
	float mfBackpackHazardBarValue;
};

class cGcAnimationLayerQueue
{
	struct AnimEntry
	{
		TkID<128> mAnimName;
		float mfBlendTime;
		int miForceLayer;
		AnimationTransitionType meTransition;
		eCurve meBlendInCurve;
		eCurve meBlendOutCurve;
		bool mbMirror;
		float mfPlayTime;
		bool mbPlaying;
	};

	cGcPlayerCharacterComponent* mpPlayerCharacterComponent;
	cTkAnimationComponent* mpAnimationComponent;
	TkID<128> mLayerName;
	cTkAnimLayerHandle mLayerHandle;
	std::deque<cGcAnimationLayerQueue::AnimEntry> mAnimationQueue;
	bool mbIsFullBodyLayer;
};

class cGcPlayerCharacterComponent : public cTkComponent
{
	class cGcPlayerControlMode
	{
		cGcPlayerControlModeEntry* mpEntry;
		cTkSmartResHandle mResource;
		cTkAttachmentPtr mpAttachment;
	};

	cGcCharacterInterface* mpCharacterInterface;
	cGcPlayerCharacterComponentData* mpData;
	cGcCharacterSuitAudio mSuitAudio;
	cGcPlayerBackpackBars mBackpackBars;
	cGcPlayerCharacterStateTable* mCharacterStateTable;
	cTkSmartResHandle mCamoMaterial;
	eCharacterState mCharacterState;
	float mTimeInCurrentState;
	float mCamoMaterialColour[4];
	float mCamoRefractionParams[4];
	cTkReplicatedVariable<eCamouflageState> meCamoState;
	bool mbCamoApplied;
	float mfTimeInCamo;
	float mfTimeCamoDisabled;
	std::array<cGcAnimationLayerQueue, 3> mAnimationQueueLayers;
	cTkAnimLayerHandle mWeaponAimLayer;
	cTkAnimLayerHandle mWeaponAimYawLayer;
	cTkAnimLayerHandle mWeaponLayer;
	cTkAnimLayerHandle mShoudlerEyeLayer;
	cTkAnimLayerHandle mHitReactLayer;
	cTkAnimLayerHandle mRideLegsLayer;
	cTkAnimLayerHandle mRideUpperBodyLayer;
	cTkAnimLayerHandle mRideUpperBodyFwdLayer;
	cTkAnimLayerHandle mBlinkAnimLayer;
	cTkAnimLayerHandle maClenchAnimLayerHandle[2];
	cTkAnimLayerHandle maLeanLayer[2];
	TkHandle mJetpackEffect;
	TkHandle mBackpackMeshGroup;
	TkHandle mJetpackEffectsParentNode;
	TkHandle mJetpackEffectMeshLight;
	TkHandle mFootDustL;
	TkHandle mFootDustR;
	TkHandle mSurfaceSwimBone;
	EffectInstance maSurfaceSwimEffects[3];
	cTkSmoothCD<float> mfSurfaceEffectStrength;
	cTkSmoothCD<float> mfRidingLean;
	cTkSmoothCD<float> mfUnderwaterJetpackBubbleStrength;
	TkHandle maUnderwaterJetpackBubbleNodes[2];
	EffectInstance maUnderwaterJetpackBubbles[2];
	EffectInstance mSplashEffect;
	float mfSplashTime;
	cTkVector<cTkSmartResHandle> maJetpackEffectMeshMaterials;
	float mfJetpackEffectMeshTimer;
	bool mbWasJetpacking;
	bool mbWasSliding;
	bool mbWasJetpackBoosted;
	float mfJetpackInitialLightIntensity;
	float mfJetpackTrailTimer;
	cTkSmoothCD<float> mfJetActivation;
	std::vector<cGcJetpackEffect> maJetpackEffects;
	std::vector<cGcPlayerCharacterComponent::cGcPlayerControlMode> maControlModes;
	TkID<128> mCurrentControlMode;
	TkID<128> mRequestedControlMode;
	bool mbFooting;
	cTkPhysicsComponent* mPhysicsComponent;
	cTkAnimationComponent* mpAnimation;
	cGcPlayerFullBodyIKComponent* mpIkComponent;
	cTkAudioComponent* mAudioComponent;
	std::array<std::function<bool __cdecl(TkID<128> const&)>, 3> mOverrideAnimInProgressFunction;
	std::array<std::function<void __cdecl(TkID<128> const&)>, 3> mOverrideAnimCompleteCallbacks;
	std::function<void __cdecl(TkID<128> const&)> mOnFullBodyAnimComplete;
	cGcThirdPersonAnimParams mThirdPersonParams;
	cGcThirdPersonAnimParams mThirdPersonParamsFinal;
	cTkVector3 mPreviousAtDirection;
	float mDeltaFacingDirectionAngle;
	float mfTimeToRagdollAfterDeath;
	float mSmoothedForwardVelocityRate;
	float mfNeckYawAngle;
	float mfNeckYawVelocity;
	float mfNeckPitchAngle;
	float mfNeckPitchVelocity;
	float mTimeInAir;
	float mTimeInAirFalling;
	float mTimeClingingToSteepSlope;
	float mfPitchSpeed;
	float mfRollSpeed;
	float mfCurrentPitch;
	float mfCurrentRoll;
	float mfCurrentCrouch;
	cTkVector3 mCurrentLean;
	bool mInBinocsView;
	bool mIsInAir;
	bool mShouldUseFallingCam;
	bool mClingingToSteepSlope;
	bool mDebugDeathPathBlocked;
	bool mbCorkscrew;
	float mfExertion;
	float mfExertionRate;
	float mfBlinkTimer;
	cTkReplicatedVariable<TkID<128> > mNetworkFullbodyAnim;
	cTkReplicatedVariable<unsigned char> miNetworkCharacterState;
	cTkReplicatedVariable<signed char> miNetworkSittingState;
	cGcNetworkInterpolationComponent* mpNetInterpolationComponent;
	TkHandle mBackpackCamNode;
	cTkPersonalRNG mRNG;
	cGcOwnerConcept mOwner;
	bool mbClonedJetpackMaterials;
};

SKYSCRAPER_END