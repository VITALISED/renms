#pragma once
#include <metadata/metadata_common.h>

class cGcRewardShipSlot
{
    static unsigned long long muNameHash = 0x5EB3ADA9F4E70000;
    static unsigned long long muTemplateHash = 0x4290FF761007EBBA;

    TkID<128> mCost;
    bool mbAwardCostAndOpenWindow;
    int miNumTokens;
    bool mbIsAlien;
    bool mbFallbackOpenWindowIfBlocked;
}
