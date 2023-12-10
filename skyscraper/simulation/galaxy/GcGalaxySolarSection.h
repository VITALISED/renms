/**
 * @file GcGalaxySolarSection.h
 * @author VITALISED & Contributors
 * @since 2023-12-09
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <skyscraper.h>

#include <simulation/galaxy/GcGalaxyTypes.h>

SKYSCRAPER_BEGIN

struct SolarQueryResult
{
    uint64_t mu64UA;
    cGcGalacticSolarSystemAddress mSolarSystemAddress;
    cTkVector3 mLocalPoint;
    cTkVector3 mGlobalPoint;
};

class cGcGalaxySolarSelection
{
  public:
    float mCountdown;
    float mTotalUpdateTime;
    std::array<float, 4> mFocusTime;
    SolarQueryResult mQuery;
    cGcGalacticVoxelCoordinate mQueryGC;
    cTkFixedString<127, char> mSystemName;
    uint16_t mVisitedPlanets;
    bool mActivating;
};

SKYSCRAPER_END