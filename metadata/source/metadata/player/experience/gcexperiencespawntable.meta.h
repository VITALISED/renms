#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcExperienceSpawnTable
{
    static unsigned long long muNameHash = 0x5F4CA33999F0D259;
    static unsigned long long muTemplateHash = 0xBFCF7EAF13124D91;

    cTkDynamicArray<cGcAIShipSpawnData> maFlybySpawns;
    cTkDynamicArray<cGcAIShipSpawnData> maOutpostSpawns;
    cTkDynamicArray<cGcAIShipSpawnData> maSpaceFlybySpawns;
    cTkDynamicArray<cGcAIShipSpawnData> maMiningFlybySpawns;
    cTkDynamicArray<cGcAIShipSpawnData> maPirateSpawns;
    cTkDynamicArray<cGcAIShipSpawnData> maPlanetaryPirateFlybySpawns;
    cTkDynamicArray<cGcAIShipSpawnData> maPlanetaryPirateRaidSpawns;
    cTkDynamicArray<cGcAIShipSpawnData> maPirateBattleSpawns;
    cTkDynamicArray<cGcAIShipSpawnData> maPoliceSpawns;
    cTkDynamicArray<cGcAIShipSpawnData> maTraderSpawns;
    cTkDynamicArray<cGcAIShipSpawnData> maAmbientSpawns;
    cTkDynamicArray<cGcAIShipSpawnData> maBattleSpawns;
    cTkDynamicArray<cGcAIShipSpawnData> maAbandonedFreighterSpawns;
    cTkDynamicArray<cGcAIShipSpawnData> maBattleInitialStandardSpawns;
    cTkDynamicArray<cGcAIShipSpawnData> maBattleInitialPirateSpawns;
    cTkDynamicArray<cGcAIShipSpawnData> maBattleSecondaryPirateSpawns;
    cTkDynamicArray<cGcBountySpawnInfo> maPirateBountySpawns;
    cTkDynamicArray<cGcPulseEncounterInfo> maPulseEncounters;
    cTkDynamicArray<cGcBackgroundSpaceEncounterInfo> maBackgroundSpaceEncounters;
    cTkDynamicArray<cGcPlayerExperienceSpawnTable> maCreatureSpawnTable;
    cTkDynamicArray<cGcPlayerExperienceSpawnArchetypeData> maCreatureSpawnArchetypes;
    cGcPlayerExperienceAsteroidCreatureSpawnTable AsteroidCreatureSpawns;
    cTkDynamicArray<cGcAIShipSpawnData> maFrigateFlybySpawns;
    cTkFixedArray<cGcSentinelSpawnSequenceGroupList> maWantedLevelSpawns;
    cTkFixedArray<cGcSentinelSpawnSequenceGroupList> maEncounterSpawns;
    cTkDynamicArray<cGcSentinelEncounterOverride> maEncounterOverrides;
    cGcSentinelWaveGroup SummonerSpawns;
    cTkDynamicArray<cGcSentinelSpawnNamedSequence> maSentinelSequences;
    cTkDynamicArray<cGcSentinelSpawnWave> maSentinelSpawns;
}
