#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gccurrency.meta.h>

class cGcRewardStatDiff
{
    static unsigned long long muNameHash = 0x9F1240710CA7E631;
    static unsigned long long muTemplateHash = 0x26EF81DE98F050DD;

    TkID<128> mCoreStat;
    TkID<128> mCompareAndSetStat;
    TkID<128> mSubstanceID;
    cGcCurrency RewardCurrency;
    int miAmountPerStat;
    int miStatRewardCap;
}
