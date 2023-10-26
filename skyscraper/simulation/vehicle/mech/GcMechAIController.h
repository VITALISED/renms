#pragma once

#include <skyscraper.h>

#include <simulation/vehicle/mech/GcMechControl.h>

SKYSCRAPER_BEGIN

class cGcMechAIController
{
	cTkHavokCharacterController* mpPhysicsController;
	cGcMechControl* mpMechControl;
	cGcMechBehaviourTree* mpBehaviourTree;
	cGcNavigation* mpNavigation;
	cGcWeapon* mpWeapon;
	eVehicleWeaponMode meCachedPlayerWeaponMode;
	eAIMechFaction meFaction;
	bool mbShowTerrainSweepDebug;
	bool mbShowCurrentAttackTarget;
};


SKYSCRAPER_END