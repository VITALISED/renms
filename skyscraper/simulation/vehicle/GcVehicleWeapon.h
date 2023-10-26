#pragma once

#include <skyscraper.h>
#include <simulation/player/GcWeapon.h>
#include <metadata/source/simulation/vehicles/gcvehicleweaponmode.meta.h>

SKYSCRAPER_BEGIN

class cGcVehicleWeapon : public cGcWeapon
{
	eVehicleWeaponMode meMode;
	float mfLastModeChangeTime;
	float mfLastFireTime;
	cGcTerrainEditorBeam mTerrainEditorBeam;
	bool mbFiredLastFrame;
};

SKYSCRAPER_END