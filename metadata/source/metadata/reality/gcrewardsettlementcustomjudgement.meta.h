#pragma once
#include <metadata/metadata_common.h>

class cGcRewardSettlementCustomJudgement
{
    static unsigned long long muNameHash = 0x93BCED5E009EBA47;
    static unsigned long long muTemplateHash = 0x3051642C59D1CC63;

    TkID<128> mCustomJudgement;
    bool mbSilent;
    bool mbCanOverrideNonCustomJudgement;
}
