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
#include <simulation/projectiles/GcLaserBeam.h>
#include <simulation/vehicle/GcVehicleWeapon.h>
#include <simulation/player/GcPlayer.h>
#include <simulation/components/gameplay/GcTechnologyAttachmentComponent.h>
#include <simulation/vehicle/GcVehicleCockpit.h>
#include <simulation/player/GcPlayerController.h>
#include <simulation/player/controllers/GcPlayerStick.h>
#include <simulation/vehicle/GcVehicleControlStick.h>
#include <simulation/vehicle/GcCarSuspensionAction.h>
#include <simulation/vehicle/GcMechControl.h>
#include <toolkit/simulation/components/TkAnimationComponent.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <metadata/simulation/vehicle/gcvehiclecomponentdata.meta.h>
#include <metadata/simulation/vehicles/gcvehicledata.meta.h>
#include <metadata/simulation/vehicles/gcmechmeshtype.meta.h>
#include <metadata/simulation/vehicles/gcmechweaponlocation.meta.h>

SKYSCRAPER_BEGIN

class cGcVehicleComponent : public cTkComponent
{
	typedef cGcPlayer::eRocketBootsDoubleTapState eCustomisationState;

	struct sMechWeaponLocationInfo
	{
		eMechWeaponLocation leActiveLocation;
		float lfTimeActivated;
	};

	struct sVehicleMech
	{
		cGcMechControl* mpMechControl;
		cGcMechAIController* mpMechAIController;
	};

	cGcVehicleComponentData* mpData;
	cGcVehicleData* mpVehicleData;
	cGcLaserBeam mLaser;
	cGcVehicleWeapon mWeapon;
	EffectInstance maWeaponMuzzleFlashHandle[4];
	cTkPhysicsComponent* mpPhysics;
	cTkAnimationComponent* mpAnim;
	cGcOwnerConcept mOwnerConcept;
	TkAudioObject mAudioObject;
	bool mbRemotelyOwnedEgineOn;
	cTkVector<TkHandle> mDamageEffectNodes;
	cTkVector<EffectInstance> mCrashEffectHandles;
	bool mbDamageEffectActive;
	cTkMatrix34 mBaseGraphicsOffsetMatrix;
	cTkMatrix34 mSpawnMatrix;
	cGcVehicleComponent::eCustomisationState meCustomisationState;
	bool mbFadeIn;
	TkHandle mBoostEffect;
	bool mbBoostEffectActive;
	float mfBoostAmount;
	bool mbBoostRecharging;
	bool mbBoostPadActive;
	float mfBoostPadTime;
	bool mbHornActive;
	TkHandle mShootPoint;
	TkHandle mGunBase;
	TkHandle mGunBarrel;
	cGcTechnologyAttachmentComponent* mpGunAttachment;
	cTkMatrix34 mGunBaseMatrix;
	cTkMatrix34 mGunBaseMatrixInitial;
	cTkMatrix34 mGunBarrelMatrix;
	cTkMatrix34 mGunBarrelMatrixInitial;
	cTkPhysRelVec3 mLastPosition;
	float mfGunTimer;
	TkHandle maaMechPartNodes[5][2];
	eMechMeshType maeActiveMechPartTypes[5];
	TkHandle mMechWeaponLocators[4];
	cGcVehicleComponent::sMechWeaponLocationInfo maActiveMechWeaponLocations[4];
	float mfFuelAccumulator;
	float mfFuelRegenAccumulator;
	float mfJumpTimer;
	float mfJumpCooldown;
	float mfForwardBackwardSteeringDecay;
	cGcVehicleCockpit mCockpit;
	cGcPlayerController* mpController;
	cGcPlayerStick mControlStick;
	cGcVehicleControlStick mThrottleControl;
	cGcVehicleControlStick mStickControl;
	TkHandle mSteeringWheelJoint;
	cTkMatrix34 mSteeringWheelInitialMatrix;
	cTkVector3 mSteeringWheelInitialOffset;
	cTkSmoothCD<float> mfSteeringWheelAngle;
	cTkSmoothCD<float> mfSteeringWheelPush;
	bool mbSteeringWheelInit;
	float mfSpawnFadeTime;
	bool mbAcceleratePressed;
	bool mbBoostPressed;
	bool mbJumpPressed;
	bool mbBraking;
	bool mbWantsExit;
	float mfExitTimer;
	float mfLaserDrainAccumulator;
	float mfProjectileDrainAccumulator;
	bool mbBoostAudioActive;
	cTkCollision mWheelGuardCollision;
	cTkRigidBody mWheelGuardBody;
	cGcCarSuspensionAction* mpSuspensionAction;
	cGcVehicleComponent::sVehicleMech mMech;
	cGcStagedJetEngine mStagedJets;
	cTkSmoothCD<float> mfVisualPower;
	cTkSmoothCD<float> mfVisualThrottle;
	cTkSmoothCD<float> mfVisualBoost;
	cTkSmoothCD<float> mfVisualTurn;
	int miNumWheels;
	TkHandle mCarWheelOwner;
	TkHandle mCarWheel[10];
	TkHandle mCarSusp[10];
	TkHandle mCarWheelDust[10];
	cTkMatrix34 mCarWheelBind[10];
	cTkMatrix34 mCarWheelParentBind[10];
	cTkMatrix34 mCarWheelSuspBind[10];
	cTkMatrix34 mCarWheelParentVehicleSpace[10];
	cTkAnimInstanceHandle mWheelAnimHandle[10];
	EffectInstance maWheelSpinEffects[10];
	EffectInstance maSkidEffects[10];
	int miAudioTorqueHistoryIndex;
	float mfAudioTorqueHistory[20];
	int miAudioSpeedHistoryIndex;
	float mfAudioSpeedHistory[20];
	float mfAudioTimeSinceImpact;
	float mfAudioLastImpactSpeed;
	float mfRemoteLastBoostingTime;
	bool mbRemoteDriver;
	float mfRemoteTurnTarget;
	float mfRemoteThrottleTarget;
	cTkVector3 mRemoteStick;
	cTkVector3 mRemoteThrottle;
	int miNumHitsSinceLastTechDamaged;
	float mfTimeOfLastTechDamageHit;
	cGcSpaceshipControl::cGcAvoidance mAvoidance;
	std::vector<cGcVehicleComponent::Headlight, TkSTLAllocatorShim<cGcVehicleComponent::Headlight, 4, -1> > maHeadlights;
	cTkSmoothCD<cTkVector2> mHeadLightSpring;
	std::vector<EffectInstance, TkSTLAllocatorShim<EffectInstance, 8, -1> > maUnderwaterEffects;
	bool mbAboveWater;
	std::vector<AnimLookup<4>, TkSTLAllocatorShim<AnimLookup<4>, 8, -1> > mapAnimations;
	TkHandle mInWorldLocator;
	bool mbScanRequested;
};


SKYSCRAPER_END