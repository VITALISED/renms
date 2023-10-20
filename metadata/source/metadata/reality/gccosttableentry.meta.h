#pragma once
#include <metadata/metadata_common.h>

class cGcCostTableEntry
{
    static unsigned long long muNameHash = 0x5923C0EE4B9AD427;
    static unsigned long long muTemplateHash = 0x2584AB024B6EDC1F;

    TkID<128> mId;
    bool mbDisplayCost;
    bool mbDontCharge;
    bool mbHideOptionAndDisplayCostOnly;
    bool mbDisplayOnlyCostIfCantAfford;
    bool mbHideCostStringIfCanAfford;
    bool mbRemoveOptionIfCantAfford;
    bool mbMustAffordInCreative;
    TkID<256> mCannotAffordOSDMsg;
    TkID<128> mMissionMessageWhenCharged;
    cTkClassPointer mCost;
}
