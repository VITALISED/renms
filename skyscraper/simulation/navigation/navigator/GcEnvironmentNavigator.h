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
#include <simulation/navigation/GcNavigationConfig.h>
#include <simulation/navigation/GcNavigationQuery.h>
#include <simulation/navigation/GcNavigationWorkingData.h>
#include <simulation/navigation/GcNavSteering.h>

SKYSCRAPER_BEGIN

class cGcEnvironmentNavigator
{
	virtual ~cGcEnvironmentNavigator();
	virtual void Prepare();
	virtual void Release();
	virtual void Init(const cGcNavigationConfig*);
	virtual void Update(float, const cGcNavigationQuery*, cGcNavigationWorkingData*);
	virtual void ApplyToSteering(float, const cGcNavigationQuery*, cGcNavSteering*);
	virtual bool IsPointNavigable(const cGcNavigationConfig*, const cTkPhysRelVec3*);
	virtual bool CanPathToPoint(const cTkPhysRelVec3*);
	virtual bool GetNearestAccessiblePoint(const cGcNavigationConfig*, const cTkPhysRelVec3*, cTkPhysRelVec3*);
	virtual bool IsStuck();
	virtual void RenderNGui();
	virtual void DebugRender(const cGcNavigationQuery*);
};

SKYSCRAPER_END