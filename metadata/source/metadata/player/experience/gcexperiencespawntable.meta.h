#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/spaceship/ai/gcaishipspawndata.meta.h>
#include <metadata/simulation/spaceship/ai/gcbountyspawninfo.meta.h>
#include <metadata/simulation/space/gcpulseencounterinfo.meta.h>
#include <metadata/simulation/space/gcbackgroundspaceencounterinfo.meta.h>
#include <metadata/gameplay/gcplayerexperiencespawntable.meta.h>
#include <metadata/gameplay/gcplayerexperiencespawnarchetypedata.meta.h>
#include <metadata/gameplay/gcplayerexperienceasteroidcreaturespawntable.meta.h>
#include <metadata/gameplay/gcsentinelspawnsequencegrouplist.meta.h>
#include <metadata/simulation/robots/gcsentinelencounteroverride.meta.h>
#include <metadata/gameplay/gcsentinelwavegroup.meta.h>
#include <metadata/gameplay/gcsentinelspawnnamedsequence.meta.h>
#include <metadata/gameplay/gcsentinelspawnwave.meta.h>

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
