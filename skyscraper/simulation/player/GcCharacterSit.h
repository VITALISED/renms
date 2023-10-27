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
#include <simulation/components/utils/GcPlayerCharacterComponent.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>
#include <metadata/simulation/ecosystem/npcs/gcnpcseatedposture.meta.h>

SKYSCRAPER_BEGIN

class cGcCharacterSit
{
	enum State
	{
		Standing,
		SittingDown,
		Seated,
		GettingUp,
		NumStates,
	};

	cGcPlayerCharacterComponent* mpCharacter;
	TkHandle mpChairNode;
	TkHandle mpSitLocationNode;
	cTkPhysRelMat34 mStartLocation;
	cTkPhysRelMat34 mTargetLocation;
	float mfTimeInState;
	float mfInterpolationProgress;
	cGcCharacterSit::State meState;
	bool mbIsGek;
	float mfNextPostureChangeTime;
	eNPCSeatedPosture meCurrentPosture;
	eNPCSeatedPosture meTargetPosture;
};


SKYSCRAPER_END