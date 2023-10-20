#pragma once
#include <metadata/metadata_common.h>
enum eTerrainSettings
{
    ETerrainSettings_FloatingIslands = 0,
    ETerrainSettings_GrandCanyon = 1,
    ETerrainSettings_MountainRavines = 2,
    ETerrainSettings_HugeArches = 3,
    ETerrainSettings_Alien = 4,
    ETerrainSettings_Craters = 5,
    ETerrainSettings_Caverns = 6,
    ETerrainSettings_Alpine = 7,
    ETerrainSettings_LilyPad = 8,
    ETerrainSettings_Desert = 9,
    ETerrainSettings_WaterworldPrime = 10,
    ETerrainSettings_FloatingIslandsPrime = 11,
    ETerrainSettings_GrandCanyonPrime = 12,
    ETerrainSettings_MountainRavinesPrime = 13,
    ETerrainSettings_HugeArchesPrime = 14,
    ETerrainSettings_AlienPrime = 15,
    ETerrainSettings_CratersPrime = 16,
    ETerrainSettings_CavernsPrime = 17,
    ETerrainSettings_AlpinePrime = 18,
    ETerrainSettings_LilyPadPrime = 19,
    ETerrainSettings_DesertPrime = 20,
}

class cTkVoxelGeneratorSettingsTypes
{
    static unsigned long long muNameHash = 0x60B0A451EF1759F9;
    static unsigned long long muTemplateHash = 0x89AB0100FEC886B9;

    eTerrainSettings TerrainSettings;
}
