#pragma once

#include <skyscraper.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <metadata/simulation/components/utils/gcplayercharactercomponentdata.meta.h>
#include <metadata/simulation/player/gcplayercharacterstatetype.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerCharacterComponent : public cTkComponent
{
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
	cTkReplicatedVariable<enum eCamouflageState> meCamoState;
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
	std::vector<cTkSmartResHandle, TkSTLAllocatorShim<cTkSmartResHandle, 4, -1> > maJetpackEffectMeshMaterials;
	float mfJetpackEffectMeshTimer;
	bool mbWasJetpacking;
	bool mbWasSliding;
	bool mbWasJetpackBoosted;
	float mfJetpackInitialLightIntensity;
	float mfJetpackTrailTimer;
	cTkSmoothCD<float> mfJetActivation;
	std::vector<cGcJetpackEffect, TkSTLAllocatorShim<cGcJetpackEffect, 16, -1> > maJetpackEffects;
	std::vector<cGcPlayerCharacterComponent::cGcPlayerControlMode, TkSTLAllocatorShim<cGcPlayerCharacterComponent::cGcPlayerControlMode, 8, -1> > maControlModes;
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