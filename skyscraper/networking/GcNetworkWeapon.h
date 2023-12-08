/**
 * @file GcNetworkWeapon.h
 * @author VITALISED & Contributors
 * @since 2023-12-08
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

#include <simulation/player/attachments/GcPlayerWeapon.h>
#include <toolkit/networking/TkNetworkId.h>
#include <toolkit/utilities/containers/TkDeque.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cGcNetworkPlayerFullSim;

class cGcNetworkWeapon
{
  public:
    struct LaserSnapshot
    {
        uint64_t muTime;
        eRemoteWeaponType meType;
        cTkVector3 mPosition;
        cTkNetworkId mTargetId;
        cTkColour mColour;
        int miDamage;
        bool mbUsed;
        cTkVector<cGcImpactCombatEffectData> maCombatEffects;
        cTkVector<cGcCombatEffectDamageMultiplier> maDamageMultipliers;
    };

    struct ProjectileSnapshot
    {
        uint64_t muTime;
        eRemoteWeaponType meType;
        cTkVector3 mPosition;
        cTkNetworkId mTargetId;
        cTkColour mColour;
        int miDamage;
        uint8_t miProjectiles;
        uint8_t miBounces;
        float mfRange;
        float mfExtraSpeed;
        float mfDispersionFactor;
        float mfExplosionRadius;
        cTkVector<cGcImpactCombatEffectData> maCombatEffects;
        cTkVector<cGcCombatEffectDamageMultiplier> maDamageMultipliers;
    };

    cGcNetworkPlayerFullSim *mpPlayer;
    bool mbPrepared;
    cGcMuzzleFlash mMuzzleFlashGun;
    cGcMuzzleFlash mMuzzleFlashLaser;
    TkHandle mWeaponBarrel;
    TkHandle mShipBarrel1;
    TkHandle mShipBarrel2;
    TkHandle mTorchNode;
    int miCurrentBarrelIndex;
    cTkFixedArray<cGcLaserBeam, 6> mLaserBeams;
    cTkDeque<cGcNetworkWeapon::LaserSnapshot> mLaserSnapshots;
    cTkPhysRelVec3 mLaserTarget;
    bool mbLaserActive;
    bool mbTorchActive;
    cTkDeque<cGcNetworkWeapon::ProjectileSnapshot> mProjectileQueue;
    robin_hood::detail::Table<
        true, 80, cTkSmartResHandle, void, robin_hood::hash<cTkSmartResHandle, void>, std::equal_to<cTkSmartResHandle>>
        mClonedMuzzleFlashMaterials;
};

SKYSCRAPER_END