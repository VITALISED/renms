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
#include <simulation/projectiles/GcProjectileImpact.h>
#include <simulation/components/gameplay/GcCombatEffectsComponent.h>
#include <simulation/environment/GcSimpleScanEffect.h>
#include <graphics/camera/shake/GcCameraShake.h>
#include <networking/components/GcNetworkComponent.h>
#include <toolkit/simulation/physics/TkPhysicsComponent.h>
#include <toolkit/networking/TkReplicatedVariable.h>
#include <toolkit/maths/geometry/TkAABB.h>
#include <toolkit/utilities/containers/TkFunctionPointerArray.h>
#include <toolkit/animation/TkHitCurve.h>
#include <metadata/source/simulation/projectiles/gcshootablecomponentdata.meta.h>

SKYSCRAPER_BEGIN

class cGcShootableComponent : public cGcNetworkComponent
{
	enum eInterceptType
	{
		EInterceptType_Ship,
		EInterceptType_Bounds,
		EInterceptType_AimNode,
	};

	class cGcDelayedImpact
	{
		cGcProjectileImpact mImpact;
		float mfDelay;
	};

	cGcShootableComponentData* mpData;
	cTkFunctionPointerArray<bool(__cdecl*)(void*, cGcProjectileImpact const&), void, 12> mCallbacks;
	cTkFunctionPointerArray<bool(__cdecl*)(void*, cGcProjectileImpact const&), void, 12> mDeathCallbacks;
	cTkReplicatedVariable<int> miStartingHealth;
	cTkReplicatedVariable<int> miNumHits;
	cTkPhysicsComponent* mpPhysics;
	cGcCombatEffectsComponent* mpCombatEffects;
	cGcProjectileImpact mLastImpact;
	cGcProjectileImpact mDeathImpact;
	bool mbAutoAimTarget;
	float mfRepairTime;
	cGcShootableComponent::eInterceptType meInterceptType;
	TkHandle mAimNode;
	cGcCameraShake mHitShake;
	cTkMatrix34 mHitShakeBase;
	bool mbHitShakeAppliedLastFrame;
	float mfLastCritTime;
	float mfFirstHitTime;
	float mfLastHitTime;
	float mfLastHitEffectTime;
	bool mbImpactEffectAllowed;
	bool mbForceCombatDamage;
	cTkAABB mOBBox;
	cTkAABB mVisibleOBBox;
	cTkHitCurve mHUDHitCurve;
	cTkVector<cTkAttachmentPtr> mapArmour;
	cTkVector<cGcSimpleScanEffect> maArmourHighlighters;
	int miNumActiveArmours;
	TkID<256> mArmourName;
	cGcSimpleScanEffect mHitEffect;
	cGcSimpleScanEffect mCriticalHitEffect;
	TkHandle mScanModel;
	bool mbRejectFalseHits;
	float mfAttackerStartTime;
	float mfAttackerLastTime;
	cTkAttachmentPtr mpAttacker;
	int miAttackDamage;
	cTkReplicatedVariable<TkID<128> > mDamageMultiplier;
	cTkReplicatedVariable<bool> mbInvincible;
	unsigned __int16 muiSurveyHandle;
	bool mbOverrideWantedLevel;
	int miCustomWantedLevelIncrease;
	bool mbPrepared;
	cTkVector<cGcShootableComponent::cGcDelayedImpact> maDelayedImpacts;
};

SKYSCRAPER_END