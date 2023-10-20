#pragma once
#include <metadata/metadata_common.h>

class cGcRewardHazard
{
    static unsigned long long muNameHash = 0xB9BE65CA55BBE004;
    static unsigned long long muTemplateHash = 0x23AB40C2528DCAC0;

    int miAmountMin;
    int miAmountMax;
    bool mbSilent;
}
