#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcExpeditionEventData
{
    static unsigned long long muNameHash = 0x48A0FEC50BBF269C;
    static unsigned long long muTemplateHash = 0x228F0F1AFB532DB0;

    TkID<256> mID;
    cTkFixedArray<float> maStatContribution;
    int miDifficultyModifier;
    int miDifficultyVarianceModifier;
    int miAdditionalShipDifficultyIncrease;
    TkID<128> mEasySuccessReward;
    TkID<128> mWhaleReward;
    TkID<128> mSuccessReward;
    TkID<128> mFailureReward;
    cGcNumberedTextList SuccessDescriptionList;
    cGcNumberedTextList SuccessWhaleDescriptionList;
    cGcNumberedTextList FailureDescriptionList;
    cGcNumberedTextList GenericSuccessDescriptionList;
    cGcNumberedTextList GenericFailureDescriptionList;
    cGcNumberedTextList GenericFailureWhaleDescriptionList;
    cGcNumberedTextList DamageDescriptionList;
    cGcNumberedTextList SecondaryDescriptionList;
    cGcNumberedTextList SecondaryFailureDescriptionList;
    cGcNumberedTextList SecondaryDamageDescriptionList;
}
