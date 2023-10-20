#pragma once
#include <metadata/metadata_common.h>

class cGcDungeonQuestParams
{
    static unsigned long long muNameHash = 0xCE00C5120C432BB0;
    static unsigned long long muTemplateHash = 0x7DEA97C7B2C9C11C;

    float mfProbability;
    cTkDynamicArray<TkID<128>> maQuestItems;
}
