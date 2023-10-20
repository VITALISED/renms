#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcScanEventSolarSystemLookup
{
    static unsigned long long muNameHash = 0xE523CFAD6AFB4BB6;
    static unsigned long long muTemplateHash = 0xDC65FBB3D6D18DC4;

    bool mbUseStarType;
    bool mbUseWealth;
    bool mbUseTrading;
    cGcAlienRace UseRace;
    cGcGalaxyStarAnomaly UseAnomaly;
    cGcPlayerConflictData UseConflict;
    cGcGalaxyStarTypes StarType;
    cGcPlanetTradingData TradingData;
    bool mbAllowUnsafeMatches;
    bool mbNeverAllowEmpty;
    bool mbNeverAllowAbandoned;
    bool mbRequireUndiscovered;
    bool mbNeedsWaterPlanet;
    bool mbNeedsPrimePlanet;
    bool mbNeedsSentinels;
    bool mbNeedsExtremeSentinelPlanet;
    bool mbNeverAllowExtremeSentinelPlanet;
    bool mbNeedsExtremeWeatherPlanet;
    bool mbNeedsExtremeHazardPlanet;
    bool mbAnyBiomeNotWeirdOrDead;
    bool mbAnyRGBBiome;
    bool mbAnyInfestedBiome;
    bool mbNeedsBiome;
    cGcBiomeType NeedsBiomeType;
    cGcBiomeSubType UseBiomeSubType;
    bool mbNeedsEmptySystem;
    bool mbNeedsAbandonedSystem;
    TkID<128> mNeedsResourceHint;
    bool mbSuitableForCreatureDiscovery;
    bool mbSuitableForCreatureTaming;
    TkID<256> mSamePlanetAsEvent;
    int miSamePlanetAsSeasonParty;
}
