#pragma once
#include <metadata/metadata_common.h>
enum eSummonEventType
{
    ESummonEventType_Summon = 0,
    ESummonEventType_Dismiss = 1,
}

class cGcMessageSummonAndDismiss
{
    static unsigned long long muNameHash = 0x67530B28A8F0F92;
    static unsigned long long muTemplateHash = 0x16D35FBC45A45F80;

    eSummonEventType SummonEventType;
}
