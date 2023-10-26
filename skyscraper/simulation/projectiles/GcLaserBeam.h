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
#include <simulation/EffectInstance.h>
#include <simulation/player/GcOwnerConcept.h>
#include <simulation/projectiles/GcBeamEffect.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <metadata/source/simulation/projectiles/gclaserbeamdata.meta.h>
#include <metadata/source/simulation/projectiles/gcprojectiledata.meta.h>

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