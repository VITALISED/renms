#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcMissionConditionExpeditionCount
{
    static unsigned long long muNameHash = 0xA4E47B76AADB4816;
    static unsigned long long muTemplateHash = 0x23379BA5EFBE3535;

    int miExpeditionCount;
    bool mbOnlyCountIfActive;
    bool mbOnlyCountIfActiveWithRemainingEvents;
    bool mbOnlyCountIfFueled;
    bool mbOnlyCountAwaitingDebrief;
    bool mbActiveExpeditionsCountAsFueled;
    cTkEqualityEnum Test;
}
