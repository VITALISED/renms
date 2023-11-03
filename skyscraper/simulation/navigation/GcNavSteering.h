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
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <simulation/navigation/GcNavigationConfig.h>
#include <simulation/navigation/GcNavigationQuery.h>
#include <simulation/navigation/GcNavigationWorkingData.h>

SKYSCRAPER_BEGIN

enum eNavSteeringInterest
{
	ENavSteeringInterest_Attraction,
	ENavSteeringInterest_Danger,
	ENavSteeringInterest_Impassable,
	ENavSteeringInterest_NumTypes = 3,
};

enum eNavSteeringInput
{
	ENavSteeringInput_FollowPath,
	ENavSteeringInput_AvoidDifficultTerrain,
	ENavSteeringInput_AvoidObstruction,
	ENavSteeringInput_NumTypes = 3,
};

class cGcNavSteering
{
	int miNumDirections;
	cTkVector3 mavDirectionsLocal[36];
	cTkVector3 mavDirectionsWorld[36];
	float mafRecipTurnRadius[36];
	float maafInterests[3][36];
	float mfDangerThreshold;
	float mfNearTargetDangerThresholdScaler;

	virtual ~cGcNavSteering();
	virtual void Prepare();
	virtual void Release();
	virtual void Init(const cGcNavigationConfig*);
	virtual void PreUpdate(const cGcNavigationQuery*);
	virtual void Update(float, const cGcNavigationQuery*, cGcNavigationWorkingData*);
	virtual void AddAvoidObstacles(cTkStackVector<cGcPathfindingObstacle>);
	virtual void AddInterest(int, eNavSteeringInterest, float, eNavSteeringInput);
	virtual void RenderNGui();
	virtual void DebugRender(const cGcNavigationQuery*);
};

SKYSCRAPER_END