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
#include <toolkit/simulation/physics/TkPhysicsComponent.h>
#include <metadata/simulation/player/gchand.meta.h>

SKYSCRAPER_BEGIN

class cGcVehicleControlStick
{
	enum Type
	{
		Stick,
		Throttle,
	};

	cGcVehicleControlStick::Type meStickType;
	eHand meStickHand;
	cTkVector2 mStickValue;
	cTkVector2 mStickMinValue;
	cTkVector2 mStickMaxValue;
	cTkVector2 mMovementSpeedLimit;
	TkHandle mStickBaseNode;
	cTkPhysicsComponent* mpStickBasePhysics;
	TkHandle mStickHandle;
	cTkMatrix34 mStickOriginalTransform;
	cTkMatrix34 mStickGrabOffset;
	float mfTimeSinceStickHeld;
	float mfStickHoldTime;
	cTkVector3 mStickBasePos;
	bool mbStickGrabbed;
	bool mbMoveStickToNeutralPosition;
};

SKYSCRAPER_END