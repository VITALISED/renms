#pragma once
#include <metadata/metadata_common.h>
enum eSprintingCostDifficulty
{
    ESprintingCostDifficulty_Free = 0,
    ESprintingCostDifficulty_Low = 1,
    ESprintingCostDifficulty_Full = 2,
}

class cGcSprintingCostDifficultyOption
{
    static unsigned long long muNameHash = 0x81A38020A4FC78BE;
    static unsigned long long muTemplateHash = 0xB2CC5E20D1D2FA20;

    eSprintingCostDifficulty SprintingCostDifficulty;
}
