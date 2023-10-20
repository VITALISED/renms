#pragma once
#include <metadata/metadata_common.h>
enum eChargingRequirementsDifficulty
{
    EChargingRequirementsDifficulty_None = 0,
    EChargingRequirementsDifficulty_Low = 1,
    EChargingRequirementsDifficulty_Normal = 2,
    EChargingRequirementsDifficulty_High = 3,
}

class cGcChargingRequirementsDifficultyOption
{
    static unsigned long long muNameHash = 0x5F6767A5FB0B2FEA;
    static unsigned long long muTemplateHash = 0xF94E671711FD8656;

    eChargingRequirementsDifficulty ChargingRequirementsDifficulty;
}
