#pragma once
#include <metadata/metadata_common.h>

class cGcRewardShield
{
    static unsigned long long muNameHash = 0x55E2192D51D7971B;
    static unsigned long long muTemplateHash = 0x505557EF5A3779E9;

    int miAmountMin;
    int miAmountMax;
    bool mbShowOSDOnSuccess;
    bool mbShowOSDOnFail;
}
