#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/solarsystem/planet/gcsolarsystemclass.meta.h>
#include <metadata/simulation/galaxy/gcgalaxystartypes.meta.h>
#include <metadata/simulation/solarsystem/planet/gcplanetgenerationinputdata.meta.h>
#include <metadata/simulation/solarsystem/gcspacestationspawndata.meta.h>
#include <metadata/simulation/solarsystem/gcsolarsystemtraderspawndata.meta.h>
#include <metadata/simulation/solarsystem/gcsolarsystemlocator.meta.h>
enum eAsteroidLevel
{
    EAsteroidLevel_NoRares = 0,
    EAsteroidLevel_SomeRares = 1,
    EAsteroidLevel_LotsOfRares = 2,
}
#include <metadata/simulation/solarsystem/planet/gcplanetcolourdata.meta.h>
#include <metadata/simulation/environment/gclightproperties.meta.h>
#include <metadata/simulation/environment/gcspaceskyproperties.meta.h>
#include <metadata/graphics/gcscreenfilters.meta.h>
#include <metadata/simulation/spaceship/ai/gcaispaceshippreloadcachedata.meta.h>
#include <metadata/reality/gcalienrace.meta.h>
#include <metadata/simulation/solarsystem/planet/gcplanettradingdata.meta.h>
#include <metadata/simulation/solarsystem/planet/gcplayerconflictdata.meta.h>

class cGcSolarSystemData
{
    static unsigned long long muNameHash = 0x9B09276BB2795541;
    static unsigned long long muTemplateHash = 0xA2E4A21CCF757F1A;

    cTkSeed mSeed;
    cTkFixedString<128,char> macName;
    cGcSolarSystemClass Class;
    cGcGalaxyStarTypes StarType;
    int miPlanets;
    cTkFixedArray<cTkVector3> maPlanetPositions;
    cTkFixedArray<cGcPlanetGenerationInputData> maPlanetGenerationInputs;
    cTkFixedArray<int> maPlanetOrbits;
    int miPrimePlanets;
    cTkVector3 mSunPosition;
    TkID<128> mAsteroidSubstanceID;
    int miNumTradeRoutes;
    int miNumVisibleTradeRoutes;
    int miMaxNumFreighters;
    bool mbStartWithFreighters;
    cTkVector2 mFreighterTimer;
    cTkVector2 mSpacePirateTimer;
    cTkVector2 mPlanetPirateTimer;
    cTkVector2 mFlybyTimer;
    cTkVector2 mPoliceTimer;
    cGcSpaceStationSpawnData SpaceStationSpawn;
    cGcSolarSystemTraderSpawnData TraderSpawnOnOutposts;
    cGcSolarSystemTraderSpawnData TraderSpawnInStations;
    cTkDynamicArray<cGcSolarSystemLocator> maLocators;
    cTkDynamicArray<cTkClassPointer> maAsteroidGenerators;
    eAsteroidLevel AsteroidLevel;
    cGcPlanetColourData Colours;
    cGcLightProperties Light;
    cGcSpaceSkyProperties Sky;
    cGcScreenFilters ScreenFilter;
    cTkFixedString<128,char> macHeavyAir;
    cTkDynamicArray<cGcAISpaceshipPreloadCacheData> maSystemShips;
    cGcAlienRace InhabitingRace;
    cGcPlanetTradingData TradingData;
    cGcPlayerConflictData ConflictData;
}
