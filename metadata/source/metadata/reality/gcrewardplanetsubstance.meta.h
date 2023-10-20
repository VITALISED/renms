#pragma once
#include <metadata/metadata_common.h>

class cGcRewardPlanetSubstance
{
    static unsigned long long muNameHash = 0x1316C386517581C1;
    static unsigned long long muTemplateHash = 0xF0FAF4739E2CE5D;

    int miAmountMin;
    int miAmountMax;
    bool mbDisableMultiplier;
    bool mbRewardAsBlobs;
    bool mbUseFuelMultiplier;
}
