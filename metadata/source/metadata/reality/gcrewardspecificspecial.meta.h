#pragma once
#include <metadata/metadata_common.h>

class cGcRewardSpecificSpecial
{
    static unsigned long long muNameHash = 0xCF9FC45A7B70BB85;
    static unsigned long long muTemplateHash = 0x7FEE336B2C12D2D8;

    TkID<128> mID;
    TkID<256> mMessage;
    bool mbShowSpecialProductPopup;
    bool mbUseSpecialFormatting;
    TkID<256> mMilestoneRewardOverrideText;
}
