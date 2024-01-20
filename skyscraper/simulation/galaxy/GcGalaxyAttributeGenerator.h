/**
 * @file GcGalaxyAttributeGenerator.h
 * @author VITALISED & Contributors
 * @since 2024-01-12
 *
 * Copyright (C) 2024  VITALISED & Contributors
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

#include <reality/gcalienrace.meta.h>
#include <simulation/galaxy/gcgalaxystartypes.meta.h>
#include <simulation/solarsystem/planet/gcplayerconflictdata.meta.h>
#include <simulation/solarsystem/planet/gctradingclass.meta.h>
#include <simulation/solarsystem/planet/gcwealthclass.meta.h>

SKYSCRAPER_BEGIN

class cGcGalaxyAttributeGenerator
{
  public:
    struct StarSystemKeyAttributes
    {
        enum Tag
        {
            Default,
            GuideStar,
        };

        enum Anomaly : uint8_t
        {
            None,
            AtlasStation,
            Blackhole,
        };

        eTradingClass meTradingClass;
        eWealthClass meWealthClass;
        eConflictLevel meConflictLevel;
        eAlienRace meRace;
        eGalaxyStarType meType;
        cGcGalaxyAttributeGenerator::StarSystemKeyAttributes::Tag meTag;
        cGcGalaxyAttributeGenerator::StarSystemKeyAttributes::Anomaly meAnomaly;
        uint32_t muPlanetCount;
        uint32_t muSafeStartPlanet;
        bool mbAbandonedSystem;
        bool mbIsPirateSystem;
        uint32_t muPrimePlanetCount;
    };
};

SKYSCRAPER_END