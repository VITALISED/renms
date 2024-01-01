/**
 * @file GcWonderManager.h
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

#include <gamestate/GcDiscoveryManager.h>
#include <gamestate/GcWonderData.h>

SKYSCRAPER_BEGIN

class cGcWonderManager : public IDiscoveryManagerEventHandler
{
  public:
    struct sWonderData
    {
        cGcWonderData maPlanets[11];
        cGcWonderData maCreatures[15];
        cGcWonderData maFlora[8];
        cGcWonderData maMinerals[8];
        cGcWonderData maTreasures[13];
        cGcWonderData maWeirdBaseParts[11];
        cGcWonderData maCustom[12];
    };

    struct sRenderData
    {
        eWonderType meActiveWonderRenderType;
        TkHandle mThumbnailsGroup;
        cTkModelResourceRenderer maThumbnailRenderers[15];
    };

    struct sDiscoveryParseData
    {
        int miNextSystemIndex;
        int miNextPlanetIndex;
        const cGcDiscoveryExport *mpDiscoveryExport;
    };

    cGcWonderManager::sWonderData mWonderData;
    cGcWonderManager::sRenderData mRenderData;
    cGcWonderManager::sDiscoveryParseData mDiscoveryParseData;
};

SKYSCRAPER_END