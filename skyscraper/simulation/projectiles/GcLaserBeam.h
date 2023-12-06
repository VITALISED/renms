/**
 * @file GcLaserBeam.h
 * @author VITALISED & Contributors
 * @since 2023-12-07
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <skyscraper.h>

#include <simulation/player/GcOwnerConcept.h>
#include <toolkit/core/types/TkHandle.h>
#include <toolkit/resources/TkResource.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>

#include <simulation/projectiles/gclaserbeamdata.meta.h>
#include <simulation/projectiles/gcprojectiledata.meta.h>

SKYSCRAPER_BEGIN

class cGcBeamEffect
{
  public:
    cTkSmartResHandle mBeamRes;
    TkHandle mBeamNode;
    TkHandle mBeamLine;
    float mfYFactor;
    float mfTimeLeft;
    int miDamageLevel;
    bool mbActive;
};

class cGcLaserBeam
{
  public:
    const cGcLaserBeamData *mpData;
    cGcProjectileData mDamageData;
    cGcOwnerConcept *mpOwnerConcept;
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