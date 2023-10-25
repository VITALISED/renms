#pragma once

#include <skyscraper.h>
#include <simulation/projectiles/GcTerrainEditorBeam.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <metadata/gamestate/gcinventoryelement.meta.h>
#include <metadata/reality/stats/gcstatstypes.meta.h>
#include <metadata/simulation/weapons/gcremoteweapons.meta.h>

SKYSCRAPER_BEGIN

class cGcMuzzleFlash
{
	cTkSmartResHandle mResource;
	TkHandle mNode;
	cTkAttachmentPtr mpAttachment;
	TkID<128> mActiveParticlesEffect;
	EffectInstance mParticlesEffectHandle;
	eRemoteWeaponType meRemoteWeaponType;
};

class cGcWeapon
{
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
	virtual const cGcInventoryElement* GetInventoryItem(int);
	virtual const cGcInventoryElement* GetActiveInventoryItem();
	virtual const cGcInventoryElement* GetActiveSecondaryInventoryItem();
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
	virtual cTkVector<bool>* GetListOfModesIfActiveOrNot(cTkVector<bool>* result);
	virtual float GetChargeFactor();
	virtual bool IsCharging();
	virtual bool IsActive();
	virtual bool IsVehicleWeapon();
	virtual cGcTerrainEditorBeam::eEditMode GetTerrainEditMode();
	virtual const cGcTerrainEditorBeam* GetTerrainEditorBeam();
	virtual bool UsingTerrainAdvancedMode();
	virtual bool ShowingTerrainEditNotifies();
	virtual void ResetTerrainMode();
	virtual bool CanCharge();
};

SKYSCRAPER_END