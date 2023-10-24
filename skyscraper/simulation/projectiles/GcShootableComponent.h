#pragma once

#include <skyscraper.h>
#include <simulation/projectiles/GcProjectileImpact.h>
#include <networking/components/GcNetworkComponent.h>
#include <toolkit/simulation/physics/TkPhysicsComponent.h>
#include <toolkit/networking/TkReplicatedVariable.h>
#include <toolkit/maths/geometry/TkAABB.h>
#include <toolkit/utilities/containers/TkFunctionPointerArray.h>
#include <metadata/simulation/projectiles/gcshootablecomponentdata.meta.h>

SKYSCRAPER_BEGIN

class cGcShootableComponent : public cGcNetworkComponent
{
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
	std::vector<cTkAttachmentPtr, TkSTLAllocatorShim<cTkAttachmentPtr, 8, -1> > mapArmour;
	std::vector<cGcSimpleScanEffect, TkSTLAllocatorShim<cGcSimpleScanEffect, 16, -1> > maArmourHighlighters;
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
	std::vector<cGcShootableComponent::cGcDelayedImpact, TkSTLAllocatorShim<cGcShootableComponent::cGcDelayedImpact, 16, -1> > maDelayedImpacts;
};

SKYSCRAPER_END