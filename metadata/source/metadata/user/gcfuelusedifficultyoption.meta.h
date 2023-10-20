#pragma once
#include <metadata/metadata_common.h>
enum eFuelUseDifficulty
{
    EFuelUseDifficulty_Free = 0,
    EFuelUseDifficulty_Cheap = 1,
    EFuelUseDifficulty_Normal = 2,
    EFuelUseDifficulty_Expensive = 3,
}

class cGcFuelUseDifficultyOption
{
    static unsigned long long muNameHash = 0x920A215A167E01E2;
    static unsigned long long muTemplateHash = 0x16E68CFACEBF2BA6;

    eFuelUseDifficulty FuelUseDifficulty;
}
