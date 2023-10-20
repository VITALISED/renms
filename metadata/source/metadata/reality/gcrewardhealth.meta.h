#pragma once
#include <metadata/metadata_common.h>

class cGcRewardHealth
{
    static unsigned long long muNameHash = 0x5A9334071F34CD7A;
    static unsigned long long muTemplateHash = 0x8BCD22590C6FFDF7;

    int miAmountMin;
    int miAmountMax;
    bool mbSilentUnlessShieldAtMax;
}
