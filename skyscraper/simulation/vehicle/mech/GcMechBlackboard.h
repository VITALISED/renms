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