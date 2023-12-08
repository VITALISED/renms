/**
 * @file GcProjectile.h
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
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/core/types/TkHandle.h>
#include <toolkit/maths/geometry/TkPhysRelVec3.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>

#include <simulation/projectiles/gccombateffectdamagemultiplier.meta.h>
#include <simulation/projectiles/gcprojectiledata.meta.h>

SKYSCRAPER_BEGIN

class cGcProjectileImpact
{
  public:
    cTkMatrix34 mMatrix;
    cTkVector3 mDirection;
    cTkRigidBodyPtr mpImpactBody;
    int miImpactMaterial;
    cGcOwnerConcept *mpOwnerConcept;
    cTkAttachmentPtr mOwnerAttachment;
    float mfTime;
    int miDamage;
    eDamageType meDamageType;
    eCombatEffectType meCombatEffectType;
    float mfExplosionRadius;
    float mfLeechValue;
    TkID<128> mProjectileID;
    TkID<128> mPlayerDamage;
    uint8_t meInstantKill[4];
    bool mbCrit;
    bool mbLaserBoost;
    bool mbIsPiercingImpact;
    bool mbRemoteMessage;
    cTkVector<cGcImpactCombatEffectData> maCombatEffects;
    cTkVector<cGcCombatEffectDamageMultiplier> maDamageMultipliers;
};

class cGcProjectile
{
  public:
    cGcProjectileData *mpData;
    TkHandle mNode;
    TkAudioObject mAudioObject;
    float mfRemainingLife;
    float mfEffectiveLife;
    cTkVector3 mDir;
    cTkPhysRelVec3 mPos;
    cTkPhysRelVec3 mStartPos;
    cTkVector3 mVelocity;
    cTkVector3 mColour;
    cGcOwnerConcept *mpOwnerConcept;
    cTkAttachmentPtr mOwnerAttachment;
    cTkRigidBodyPtr mpTarget;
    int miIgnoreCollision;
    int miBounceCount;
    int miTotalBounces;
    int miDamage;
    eDamageType meDamageType;
    bool mbTracking;
    float mfSpeed;
    float mfExplosionRadius;
    float mfScale;
    bool mbHoming;
    bool mbHomingLaser;
    bool mbCrit;
    cTkVector<cGcImpactCombatEffectData> maCombatEffects;
    cTkVector<cGcCombatEffectDamageMultiplier> maCombatEffectsDmgMultipliers;
    float mfLeechValue;
    TkHandle mBeamLine;
};

SKYSCRAPER_END