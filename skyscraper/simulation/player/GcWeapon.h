/**
 * @file GcWeapon.h
 * @author VITALISED & Contributors
 * @since 2023-12-06
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

#include <simulation/projectiles/GcTerrainEditorBeam.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <gamestate/gcinventoryelement.meta.h>
#include <reality/stats/gcstatstypes.meta.h>
#include <simulation/weapons/gcremoteweapons.meta.h>

SKYSCRAPER_BEGIN

class cGcMuzzleFlash
{
  public:
    cTkSmartResHandle mResource;
    TkHandle mNode;
    cTkAttachmentPtr mpAttachment;
    TkID<128> mActiveParticlesEffect;
    EffectInstance mParticlesEffectHandle;
    eRemoteWeaponType meRemoteWeaponType;
};

class cGcAvailableWeapons
{
  public:
    class cGcAvailableWeaponInfo
    {
      public:
        cTkSmartResHandle mWeaponResource;
        bool mbIsSecret;
    };
    cTkVector<cGcAvailableWeapons::cGcAvailableWeaponInfo> maAvailableWeapons;
};

class cGcWeapon
{
  public:
    virtual bool UsingAmmo();
    virtual bool UsesInventoryAmmo();
    virtual int GetAvailableAmmo();
    virtual int GetClipSize();
    virtual bool IsReloading();
    virtual float GetReloadProgress();
    virtual float GetLastFireTime();
    virtual bool HasOverheated();
    virtual float GetOverHeatTime();
    virtual float GetOverheatProgress();
    virtual bool IsOnCooldown();
    virtual float GetCooldownDuration();
    virtual float GetCooldownProgress();
    virtual int GetAmmoInClip(bool);
    virtual const cGcInventoryElement *GetInventoryItem(int);
    virtual const cGcInventoryElement *GetActiveInventoryItem();
    virtual const cGcInventoryElement *GetActiveSecondaryInventoryItem();
    virtual float GetHeatFactor();
    virtual float GetHeatWarningFactor();
    virtual float GetAlertPoint();
    virtual float GetCooldownFactor();
    virtual int GetModeIndex();
    virtual float GetLastModeChangeTime();
    virtual int GetNumModes();
    virtual void SetModeIndex(int);
    virtual float GetWeaponRange(int);
    virtual float GetWeaponSpeed(int);
    virtual eStatsType GetPrimaryStat();
    virtual bool IsCriticalShot();
    virtual cTkVector<bool> *GetListOfModesIfActiveOrNot(cTkVector<bool> *result);
    virtual float GetChargeFactor();
    virtual bool IsCharging();
    virtual bool IsActive();
    virtual bool IsVehicleWeapon();
    virtual cGcTerrainEditorBeam::eEditMode GetTerrainEditMode();
    virtual const cGcTerrainEditorBeam *GetTerrainEditorBeam();
    virtual bool UsingTerrainAdvancedMode();
    virtual bool ShowingTerrainEditNotifies();
    virtual void ResetTerrainMode();
    virtual bool CanCharge();
};

SKYSCRAPER_END