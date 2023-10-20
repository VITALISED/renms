#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gccurrency.meta.h>

class cGcMissionSequenceCollectMoney
{
    static unsigned long long muNameHash = 0x839AE0F21C2F266C;
    static unsigned long long muTemplateHash = 0x9426ADEECBC83FEE;

    cTkFixedString<128,char> macMessage;
    int miAmount;
    cGcCurrency CollectCurrency;
    bool mbTakeAmountFromSeasonData;
    bool mbApplyDifficultyScaling;
    cTkFixedString<128,char> macDebugText;
    TkID<128> mForItemID;
    int miForItemQuantity;
    bool mbDiscountAlreadyAcquiredForItems;
}
