#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcGalaxyStarAttributesData
{
    static unsigned long long muNameHash = 0xEDE680300A536215;
    static unsigned long long muTemplateHash = 0x636E887ED3223018;

    cGcGalaxyStarTypes Type;
    cGcGalaxyStarAnomaly Anomaly;
    int miNumberOfPlanets;
    int miNumberOfPrimePlanets;
    cTkFixedArray<cGcPlanetSize> maPlanetSizes;
    cTkFixedArray<int> maPlanetParentIndices;
    cTkFixedArray<cTkSeed> maPlanetSeeds;
    cGcPlanetTradingData TradingData;
    cGcPlayerConflictData ConflictData;
    cGcAlienRace Race;
    bool mbAbandonedSystem;
    bool mbIsPirateSystem;
    bool mbIsSystemSafe;
}
