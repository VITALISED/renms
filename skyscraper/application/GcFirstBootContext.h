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

#include <atlas/WinHttpTask.h>
#include <simulation/galaxy/GcGalaxyTypes.h>
#include <toolkit/simulation/TkSeed.h>

SKYSCRAPER_BEGIN

struct SystemSeed
{
    uint64_t mu64Hash1;
    uint64_t mu64Hash2;
};

class cGcFirstBootContext
{
  public:
    typedef WinHttpTask::State::Enum State;

    enum GenerationMode
    {
        Random,
        BlackHoleDestination,
        StoryPortalPlanet,
    };

    cGcFirstBootContext::State meState;
    cGcFirstBootContext::GenerationMode meGenerationMode;
    SystemSeed mSystemSeed;
    cTkSeed mStarSeed;
    cGcGalacticVoxelCoordinate mBootCoordinate;
    int32_t miDestinationIndex;
    uint64_t mResultSpawnUA;
};

SKYSCRAPER_END