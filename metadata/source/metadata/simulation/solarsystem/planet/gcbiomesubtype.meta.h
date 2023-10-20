#pragma once
#include <metadata/metadata_common.h>
enum eBiomeSubType
{
    EBiomeSubType_None = 0,
    EBiomeSubType_Standard = 1,
    EBiomeSubType_HighQuality = 2,
    EBiomeSubType_Structure = 3,
    EBiomeSubType_Beam = 4,
    EBiomeSubType_Hexagon = 5,
    EBiomeSubType_FractCube = 6,
    EBiomeSubType_Bubble = 7,
    EBiomeSubType_Shards = 8,
    EBiomeSubType_Contour = 9,
    EBiomeSubType_Shell = 10,
    EBiomeSubType_BoneSpire = 11,
    EBiomeSubType_WireCell = 12,
    EBiomeSubType_HydroGarden = 13,
    EBiomeSubType_HugePlant = 14,
    EBiomeSubType_HugeLush = 15,
    EBiomeSubType_HugeRing = 16,
    EBiomeSubType_HugeRock = 17,
    EBiomeSubType_HugeScorch = 18,
    EBiomeSubType_HugeToxic = 19,
    EBiomeSubType_Variant_A = 20,
    EBiomeSubType_Variant_B = 21,
    EBiomeSubType_Variant_C = 22,
    EBiomeSubType_Variant_D = 23,
    EBiomeSubType_Infested = 24,
    EBiomeSubType_Swamp = 25,
    EBiomeSubType_Lava = 26,
}

class cGcBiomeSubType
{
    static unsigned long long muNameHash = 0xE8FE27493120750F;
    static unsigned long long muTemplateHash = 0xAA4AA33B8FCAE03E;

    eBiomeSubType BiomeSubType;
}
