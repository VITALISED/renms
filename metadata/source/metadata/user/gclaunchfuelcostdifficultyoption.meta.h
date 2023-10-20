#pragma once
#include <metadata/metadata_common.h>
enum eLaunchFuelCostDifficulty
{
    ELaunchFuelCostDifficulty_Free = 0,
    ELaunchFuelCostDifficulty_Low = 1,
    ELaunchFuelCostDifficulty_Normal = 2,
    ELaunchFuelCostDifficulty_High = 3,
}

class cGcLaunchFuelCostDifficultyOption
{
    static unsigned long long muNameHash = 0xB8138F7D4F230C2B;
    static unsigned long long muTemplateHash = 0x6DA718B3683C3F52;

    eLaunchFuelCostDifficulty LaunchFuelCostDifficulty;
}
