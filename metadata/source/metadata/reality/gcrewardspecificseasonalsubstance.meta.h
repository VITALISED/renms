#pragma once
#include <metadata/metadata_common.h>

class cGcRewardSpecificSeasonalSubstance
{
    static unsigned long long muNameHash = 0xD772C003DA86A5A1;
    static unsigned long long muTemplateHash = 0x2B80AD700CFA7BB9;

    TkID<128> mID;
    int miAmountMin;
    int miAmountMax;
    float mfChanceToUse;
    int miSeasonNumber;
}
