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
#include <toolkit/utilities/containers/TkVector.h>
#include <simulation/navigation/GcNavObstacleTracker.h>
#include <simulation/navigation/GcNavSteering.h>
#include <simulation/navigation/navigator/GcEnvironmentNavigator.h>
#include <simulation/navigation/GcNavigationResult.h>

SKYSCRAPER_BEGIN

class cGcNavigation
{
	cTkVector<cGcNavObstacleTracker*> mapObstacleTrackers;
	cGcEnvironmentNavigator* mpNavigator;
	cGcNavSteering* mpSteering;
	cGcNavigationQuery mNavQuery;
	cGcNavigationResult mNavResult;
	bool mbDebugBreak;
};

SKYSCRAPER_END