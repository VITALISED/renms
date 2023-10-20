#pragma once
#include <metadata/metadata_common.h>
enum eNoiseVoxelType
{
    ENoiseVoxelType_Base = 0,
    ENoiseVoxelType_Rock = 1,
    ENoiseVoxelType_Mountain = 2,
    ENoiseVoxelType_Sand = 3,
    ENoiseVoxelType_Cave = 4,
    ENoiseVoxelType_Substance_1 = 5,
    ENoiseVoxelType_Substance_2 = 6,
    ENoiseVoxelType_Substance_3 = 7,
    ENoiseVoxelType_RandomRock = 8,
    ENoiseVoxelType_RandomRockOrSubstance = 9,
}

class cTkNoiseVoxelTypeEnum
{
    static unsigned long long muNameHash = 0xA54BFECBD79D65EE;
    static unsigned long long muTemplateHash = 0x23F660CE1EB9E712;

    eNoiseVoxelType NoiseVoxelType;
}
