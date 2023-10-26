#pragma once

#include <skyscraper.h>
#include <simulation/vehicle/mech/GcMechControl.h>
#include <simulation/navigation/GcNavigation.h>
#include <toolkit/simulation/ai/behaviourtree/TkBehaviourTree.h>

SKYSCRAPER_BEGIN

enum eAIMechFaction
{
	EAIMechFaction_Player,
	EAIMechFaction_Sentinel,
};

class cGcMechBehaviourTree : public cTkBehaviourTree
{
	cTkAttachment* mpAttachment;
	cGcMechControl* mpMechControl;
	cGcNavigation* mpNavigation;
	cTkHavokCharacterController* mpPhysicsController;
	eAIMechFaction meFaction;
	cGcMechBlackboard mBlackboard;
};

SKYSCRAPER_END