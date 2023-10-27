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
#include <simulation/player/GcWeapon.h>
#include <simulation/projectiles/GcLaserBeam.h>
#include <simulation/environment/GcSimpleScanEffect.h>
#include <graphics/GcInWorldUIManager.h>
#include <graphics/ngui/GcNGui.h>
#include <toolkit/utilities/containers/TkClassPool.h>
#include <toolkit/system/timer/TkTimer.h>
#include <metadata/simulation/weapons/gcplayerweapons.meta.h>
#include <metadata/simulation/gcweaponclasses.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerWeapon : public cGcWeapon
{
	typedef cGcInWorldUIManager::cGcScreenProjector::RepositioningState eReloadHolsterState;
	typedef cGcPlayerShipOwnership::eMeshRefreshState eMeshRefreshState;

	enum eWeaponState
	{
		EWeapon_Holstered,
		EWeapon_Holstering,
		EWeapon_Idle,
		EWeapon_Drawing,
		EWeapon_Cocking,
		EWeapon_Cocked,
		EWeapon_Meleeing,
		EWeapon_Reloading,
		EWeapon_ReloadHolstered,
		EWeapon_Examining,
		EWeapon_NumStates = 10,
	};

	cTkDynamicTexture mScreenTexture;
	cGcNGui mScreenGui;
	cTkSmartResHandle mWeaponResource;
	cTkFixedArray<cGcMuzzleFlash, 19> maMuzzleFlashGun;
	cTkFixedArray<cGcMuzzleFlash, 19> maMuzzleFlashLaser;
	eWeaponMode meReloadRequest;
	TkHandle mEquipmentNode;
	TkHandle mWeaponNode;
	TkHandle mWeaponRootJointNode;
	TkHandle mWeaponGunJointNode;
	TkHandle mWeaponBarrelNode;
	cTkSeed mWeaponSeed;
	TkHandle mNonDominantLeftHandIkLocator;
	TkHandle mDominantRightHandIkLocator;
	bool mbHandInHolsterPosition;
	bool mbHolsterGestureAvailable;
	cTkAnimLayerHandle mpAnimationLayer;
	eWeaponMode meRequestedWeaponMode;
	bool mbWasControlTracking;
	eWeaponMode meWeaponMode;
	eWeaponMode meAltWeaponMode;
	bool mbHasValidAltWeapon;
	float mfAnimModeTimer;
	float mfWeaponModeChangeTime;
	TkAudioObject mAudioObject;
	cTkVector3 mBarrelVelocity;
	cTkVector3 mBarrelPrevPos;
	cTkSmoothCD<float> mWeaponFader;
	cTkMatrix34 mOffset;
	cTkPhysRelMat34 mWeaponMatrix;
	cTkSmoothCD<float> mfAimAdjustStrength;
	cTkMatrix34 mThirdPersonRHDominantHandOffset;
	cTkMatrix34 mThirdPersonLHNonDominantHandOffset;
	cGcLaserBeam mLaserBeam;
	cGcLaserBeam mRailBeam;
	cGcLaserBeam mBoltBeam;
	cGcTerrainEditorBeam mTerrainEditorBeam;
	float mfMeleeTimer;
	bool mbMeleeHit;
	bool mbMeleeBoosted;
	cTkClassPoolHandle mLaserShake;
	float mfHeatTime;
	float mfLaserAmmoTime;
	float mfCoolSpeed;
	bool mbOverheat;
	float mfCooldownTime;
	bool mbOnCooldown;
	int miProjectileSeed;
	bool mbFireOnCocked;
	eWeaponMode meCockFireMode;
	eWeaponStatClass meWeaponStatClass;
	cTkAnimationComponent* mpAnim;
	cTkSmartResHandle mShieldRes;
	TkHandle mShieldNode;
	cTkPhysicsComponent* mpShieldPhysics;
	cTkSmoothCD<float> mShieldActiveFactor;
	bool mbShieldActivate;
	cTkSmoothCD<float> mStealthActiveFactor;
	bool mbStealthActivate;
	float mfStealthChargeAccumulator;
	TkHandle mMuzzleLightNode;
	float mfScopeFOVMultiplier;
	cGcPlayerWeapon::eWeaponState meState;
	bool mbHolsterWeaponAfterMelee;
	cTkTimerTemplate<0> mWeaponTimer;
	float mfLastFireTime;
	float mfLastHolsterTime;
	bool mbFiredLastFrame;
	bool mbFiredThisFrame;
	bool mbHolsterChangeActive;
	float mfDispersionTimer;
	TkID<128> mActiveOneShot;
	TkID<128> mMeleeAnim;
	cGcOwnerConcept* mpOwnerConcept;
	int maiAmmo[19];
	TkID<128> maKnockbackAnims[10];
	int miNumKnockbackAnims;
	float mfReloadButtonHeldTime;
	cGcPlayerWeapon::eReloadHolsterState mReloadHolsterState;
	bool mbIsLargeWeapon;
	bool mbReloadTapDown;
	bool mbCharging;
	float mfChargeTime;
	eWeaponMode meNeedsRecoilAfterFired;
	cGcSimpleScanEffect mScanEffect;
	bool mbShouldRefreshMesh;
	cGcPlayerWeapon::eMeshRefreshState mMeshRefreshState;
	cTkSmartResHandle mWeaponModelSwapRes;
	cTkTimerTemplate<0> mVrMeleeTimer;
	TkHandle mSpawnedNode;
	TkHandle mSpawnedAltNode;
	int miShotsInBurst;
};

SKYSCRAPER_END