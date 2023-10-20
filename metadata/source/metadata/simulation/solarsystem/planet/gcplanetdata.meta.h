#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/environment/gcplanetlife.meta.h>
#include <metadata/simulation/solarsystem/planet/gcplanethazarddata.meta.h>
enum eResourceLevel
{
    EResourceLevel_Low = 0,
    EResourceLevel_High = 1,
}
#include <metadata/simulation/environment/gcbuildingdensitylevels.meta.h>
#include <metadata/simulation/solarsystem/planet/gcplanetdataresourcehint.meta.h>
#include <metadata/simulation/solarsystem/planet/gcplanetcolourdata.meta.h>
#include <metadata/simulation/solarsystem/planet/gcplanetweatherdata.meta.h>
#include <metadata/simulation/environment/gcplanetcloudproperties.meta.h>
#include <metadata/simulation/solarsystem/planet/gcplanetwaterdata.meta.h>
#include <metadata/voxel/generator/tkvoxelgeneratordata.meta.h>
#include <metadata/simulation/environment/gcenvironmentspawndata.meta.h>
#include <metadata/reality/gcalienrace.meta.h>
#include <metadata/simulation/environment/gcplanetbuildingdata.meta.h>
#include <metadata/simulation/solarsystem/planet/gcplanetgenerationintermediatedata.meta.h>
#include <metadata/simulation/solarsystem/planet/gcplanetinfo.meta.h>
#include <metadata/simulation/solarsystem/planet/gcplanetsentineldata.meta.h>
#include <metadata/simulation/solarsystem/planet/gcplanetringdata.meta.h>

class cGcPlanetData
{
    static unsigned long long muNameHash = 0x25EDFA0EC4C3AF0A;
    static unsigned long long muTemplateHash = 0x2DC122FA5D947C91;

    cTkFixedString<128,char> macName;
    cGcPlanetLife Life;
    cGcPlanetLife CreatureLife;
    cGcPlanetHazardData Hazard;
    eResourceLevel ResourceLevel;
    cGcBuildingDensityLevels BuildingLevel;
    TkID<128> mCommonSubstanceID;
    TkID<128> mUncommonSubstanceID;
    TkID<128> mRareSubstanceID;
    cTkDynamicArray<cGcPlanetDataResourceHint> maExtraResourceHints;
    cGcPlanetColourData Colours;
    cTkFixedArray<cTkColour> maTileColours;
    cGcPlanetWeatherData Weather;
    cGcPlanetCloudProperties Clouds;
    cGcPlanetWaterData Water;
    cTkFixedString<128,char> macTerrainFile;
    cTkVoxelGeneratorData Terrain;
    int miTileTypeSet;
    cTkDynamicArray<int> maTileTypeIndices;
    cGcEnvironmentSpawnData SpawnData;
    cGcAlienRace InhabitingRace;
    cGcPlanetBuildingData BuildingData;
    cGcPlanetGenerationIntermediateData GenerationData;
    cTkVector2 mSentinelTimer;
    cTkVector2 mFlybyTimer;
    cGcPlanetInfo PlanetInfo;
    cGcPlanetSentinelData SentinelData;
    cGcPlanetRingData Rings;
    bool mbInEmptySystem;
    bool mbInAbandonedSystem;
    float mfFuelMultiplier;
}
