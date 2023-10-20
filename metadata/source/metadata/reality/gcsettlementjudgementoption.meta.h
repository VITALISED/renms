#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcsettlementjudgementperkoption.meta.h>
#include <metadata/reality/gcsettlementstatchange.meta.h>

class cGcSettlementJudgementOption
{
    static unsigned long long muNameHash = 0x64786DD8F4475C9B;
    static unsigned long long muTemplateHash = 0xBADC6797B5A16762;

    TkID<256> mOptionText;
    cTkDynamicArray<cGcSettlementJudgementPerkOption> maPerks;
    bool mbHidePerkInJudgement;
    cTkDynamicArray<cGcSettlementStatChange> maStatChanges;
    cTkDynamicArray<TkID<128>> maAdditionalRewards;
    TkID<128> mChainedJudgementID;
    bool mbUsePolicyPerk;
    bool mbUsePolicyStat;
    bool mbUseGiftReward;
    bool mbUseTechPerk;
    bool mbOptionIsPositiveForNPC;
}
