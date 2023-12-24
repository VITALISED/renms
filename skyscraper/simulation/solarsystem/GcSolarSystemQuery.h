/**
 * @file GcSolarSystemQuery.h
 * @author VITALISED & Contributors
 * @since 2023-12-10
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
#include <simulation/solarsystem/GcSolarSystemGenerator.h>
#include <simulation/solarsystem/planet/GcPlanetGenerator.h>

#include <simulation/environment/gcbuildingdensitylevels.meta.h>
#include <simulation/environment/weather/gcweatheroptions.meta.h>
#include <simulation/solarsystem/planet/gcplanetdataresourcehint.meta.h>
#include <simulation/solarsystem/planet/gcplanetweatherdata.meta.h>
#include <toolkit/voxel/generator/tkvoxelgeneratorsettingstypes.meta.h>

SKYSCRAPER_BEGIN

struct PlanetGenerationQuery
{
    cTkFixedString<127, char> mName;
    eBiome meBiome;
    eBiomeSubType meBiomeSubType;
    TkID<128> mCommonSubstanceID;
    TkID<128> mUncommonSubstanceID;
    TkID<128> mRareSubstanceID;
    eBuildingDensity meBuildingDensity;
    cTkVector<cGcPlanetObjectSpawnData> maDetailObjects;
    cTkVector<cGcPlanetObjectSpawnData> maObjects;
    cTkVector<cGcPlanetObjectSpawnData> maLandmarks;
    cTkVector<cGcPlanetObjectSpawnData> maDistantObjects;
    cTkVector<cGcPlanetDataResourceHint> maResourceHints;
    bool mbHasWater;
    bool mbHasCaves;
    bool mbHasRings;
    bool mbHasSentinels;
    bool mbHasExtremeSentinels;
    bool mbHasExtremeWeather;
    bool mbHasExtremeHazard;
    bool mbIsPrime;
    eTerrainSettings meTerrainSettings;
    bool mbSuitableForCreatureDiscovery;
    bool mbSuitableForCreatureTaming;
    cTkColour mMainColour;
    cTkColour mWaterColour;
    float mfDiscoveryImageCloudIntensity;
    eWeather meWeather;
    eStormFrequency meStormFrequency;
};

class cGcSolarSystemQuery
{
  public:
    enum Type
    {
        System,
        SystemAndPlanets,
    };

    cGcSolarSystemQuery::Type meType;
    uint64_t mSystemUA;
    cTkSeed mSystemSeed;
    cGcGalaxyAttributesAtAddress mSystemAttributes;
    PlanetGenerationQuery maPlanetAttributes[6];
    cGcSolarSystemGenerator::GenerationData mSolarSystemGenerationData;
    cGcSolarSystemData mSolarSystemData;
    cGcSolarSystemAsteroidFields mSolarSystemInfoMap;

    cGcSolarSystemQuery();
    void Run(uint64_t lUA, cGcSolarSystemQuery::Type leType, bool lbGenerateObjectLists);
};

SKYSCRAPER_END