#pragma once
#include <metadata/metadata_common.h>
enum eEnergyDrainDifficulty
{
    EEnergyDrainDifficulty_Slow = 0,
    EEnergyDrainDifficulty_Normal = 1,
    EEnergyDrainDifficulty_Fast = 2,
}

class cGcEnergyDrainDifficultyOption
{
    static unsigned long long muNameHash = 0xCB8A748BB740CFAE;
    static unsigned long long muTemplateHash = 0x8110581C7BD94717;

    eEnergyDrainDifficulty EnergyDrainDifficulty;
}
