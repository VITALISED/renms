#pragma once
#include <metadata/metadata_common.h>
enum eFeedbackType
{
    EFeedbackType_None = 0,
    EFeedbackType_Feedback = 1,
    EFeedbackType_Weapon = 2,
    EFeedbackType_Vibration = 3,
}

class cTkTriggerFeedbackData
{
    static unsigned long long muNameHash = 0x5DE2B54C774CA122;
    static unsigned long long muTemplateHash = 0x5D8E386894CA5E6B;

    eFeedbackType FeedbackType;
    float mfStrength;
    float mfPosition;
    float mfFrequency;
}
