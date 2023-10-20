#pragma once
#include <metadata/metadata_common.h>
enum eBiome
{
    EBiome_Lush = 0,
    EBiome_Toxic = 1,
    EBiome_Scorched = 2,
    EBiome_Radioactive = 3,
    EBiome_Frozen = 4,
    EBiome_Barren = 5,
    EBiome_Dead = 6,
    EBiome_Weird = 7,
    EBiome_Red = 8,
    EBiome_Green = 9,
    EBiome_Blue = 10,
    EBiome_Test = 11,
    EBiome_Swamp = 12,
    EBiome_Lava = 13,
    EBiome_Waterworld = 14,
    EBiome_All = 15,
}

class cGcBiomeType
{
    static unsigned long long muNameHash = 0x5CEE315FE3457560;
    static unsigned long long muTemplateHash = 0x9F5CC8BA811F301D;

    eBiome Biome;
}
