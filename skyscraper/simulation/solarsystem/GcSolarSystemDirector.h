/**
 * @file GcSolarSystemDirector.h
 * @author VITALISED & Contributors
 * @since 2023-12-11
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

#include <simulation/solarsystem/routes/GcTradeRoute.h>
#include <toolkit/utilities/containers/TkClassPool.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/random/TkPersonalRNG.h>

SKYSCRAPER_BEGIN

class cGcSolarSystemDirector
{
  public:
    cTkPersonalRNG mDirectorRNG;
    uint64_t mu64BaseRNGSeed;
    bool mDirectorEnabled;
    float mfTime;
    cTkVector<cGcTradeRoute> maRoutes;
    int miNumVisibleRoutes;
    cTkClassPoolHandle mTraderSquad;
    robin_hood::detail::Table<
        true, 80, /*cGcOutpostComponent*/ uintptr_t *, void,
        robin_hood::hash</*cGcOutpostComponent*/ uintptr_t *, void>, std::equal_to</*cGcOutpostComponent*/ uintptr_t *>>
        mPopulatedOutposts;
};

SKYSCRAPER_END