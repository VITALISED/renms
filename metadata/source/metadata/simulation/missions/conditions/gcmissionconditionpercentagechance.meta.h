#pragma once
#include <metadata/metadata_common.h>

class cGcMissionConditionPercentageChance
{
    static unsigned long long muNameHash = 0xA420A86F131CF88;
    static unsigned long long muTemplateHash = 0x6809A50B1268BBE;

    int miPercent;
    bool mbSeeded;
    bool mbOverrideZeroSeed;
    bool mbOverrideMissionSeedWithRandomSeed;
}
