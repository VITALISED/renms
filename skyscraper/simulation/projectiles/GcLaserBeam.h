#pragma once

#include <skyscraper.h>
#include <simulation/EffectInstance.h>
#include <simulation/player/GcOwnerConcept.h>
#include <simulation/projectiles/GcBeamEffect.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <metadata/simulation/projectiles/gclaserbeamdata.meta.h>
#include <metadata/simulation/projectiles/gcprojectiledata.meta.h>

SKYSCRAPER_BEGIN

class cGcLaserBeam
{
	const cGcLaserBeamData* mpData;
	cGcProjectileData mDamageData;
	cGcOwnerConcept* mpOwnerConcept;
	TkID<128> mDebugTag;
	TkAudioObject mAudioObject;
	cGcBeamEffect mBeam;
	cGcBeamEffect mBeamCore;
	bool mbActive;
	bool mbDeferred;
	bool mbDeferredCheck;
	cTkRigidBodyPtr mpHitBody;
	cTkPhysRelVec3 mHitPoint;
	cTkVector3 mHitNormal;
	int miHitMaterial;
	cTkPhysRelVec3 mStartPoint;
	cTkPhysRelVec3 mEndPoint;
	float mfMiningTime;
	cTkRigidBodyPtr mpMiningBody;
	float mfStartTime;
	float mfLastHitTime;
	float mfLastFireTime;
	bool mbFiredThisFrame;
	int miDamageLevel;
	float mfLeechValue;
	TkHandle mLight;
	EffectInstance mLaserMuzzleFlashEffectHandle;
	EffectInstance mLaserImpactEffectHandle;
	TkID<128> mLaserImpactEffect;
	float mfLaserImpactSize;
	float mfMiningSpeedMultiplier;
	float mfMiningRadiusMultiplier;
	cTkColour mColour;
	float mfDebrisTime;
	float mfWidthBoost;
	bool mbHeatBoostNumbers;
	bool mbTracerMode;
	cTkVector<cGcImpactCombatEffectData> maCombatEffects;
	cTkVector<cGcCombatEffectDamageMultiplier> maCombatEffectsDmgMultipliers;
};

SKYSCRAPER_END