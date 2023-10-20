#pragma once
#include <metadata/metadata_common.h>
enum eHazardDrainDifficulty
{
    EHazardDrainDifficulty_Slow = 0,
    EHazardDrainDifficulty_Normal = 1,
    EHazardDrainDifficulty_Fast = 2,
}

class cGcHazardDrainDifficultyOption
{
    static unsigned long long muNameHash = 0x56BC170774FBDFB4;
    static unsigned long long muTemplateHash = 0x4263632D17FDFC6D;

    eHazardDrainDifficulty HazardDrainDifficulty;
}
