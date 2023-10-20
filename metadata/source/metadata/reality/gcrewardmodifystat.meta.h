#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/stats/gcstatmodifytype.meta.h>

class cGcRewardModifyStat
{
    static unsigned long long muNameHash = 0x3E0EF3AAF2E4B272;
    static unsigned long long muTemplateHash = 0x39A30AD98B79A092;

    TkID<128> mStat;
    TkID<128> mOtherStat;
    int miAmount;
    bool mbUseOtherStat;
    cGcStatModifyType ModifyType;
}
