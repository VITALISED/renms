#pragma once

#include <skyscraper.h>

#include <simulation/galaxy/GcGalaxyTypes.h>
#include <simulation/solarsystem/GcSolarSystemAsteroidFields.h>
#include <simulation/solarsystem/GcSolarSystemGenerator.h>
#include <simulation/solarsystem/planet/GcPlanet.h>
#include <toolkit/simulation/TkSeed.h>
#include <toolkit/utilities/TkString.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <simulation/environment/gcbuildingdensitylevels.meta.h>
#include <simulation/environment/weather/gcweatheroptions.meta.h>
#include <simulation/solarsystem/gcsolarsystemdata.meta.h>
#include <simulation/solarsystem/planet/gcbiomesubtype.meta.h>
#include <simulation/solarsystem/planet/gcbiometype.meta.h>
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
    enum Type
    {
        system,
        SystemAndPlanets,
    };

    cGcSolarSystemQuery::Type meType;
    unsigned __int64 mSystemUA;
    cTkSeed mSystemSeed;
    cGcGalaxyAttributesAtAddress mSystemAttributes;
    PlanetGenerationQuery maPlanetAttributes[6];
    cGcSolarSystemGenerator::GenerationData mSolarSystemGenerationData;
    cGcSolarSystemData mSolarSystemData;
    cGcSolarSystemAsteroidFields mSolarSystemInfoMap;
};

SKYSCRAPER_END