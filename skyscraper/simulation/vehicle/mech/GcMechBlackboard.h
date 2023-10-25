#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class cGcMechBlackboard
{
	cGcPlayer* mpPlayerOwner;
	sMechTargetData mCurrentTarget;
	eEncounterType meEncounterType;
	float mfLastKnownTime;
	cTkPhysRelVec3 mvLastKnownTargetPos;
	bool mbIsFiring;
	float mfTimeOfLastFire;
	cTkPhysRelVec3 mvLastFireTargetPos;
	cTkRigidBody* mpLastFireTargetBody;
	float mfAlertChangeTime;
	float mfAlertEscalateTime;
	bool mbIsJumpEnabled;
	eMechAlertness meAlert;
};

SKYSCRAPER_END