#pragma once
#include <metadata/metadata_common.h>

class cGcInventoryCostDataEntry
{
    static unsigned long long muNameHash = 0xD9472E9B798FC3B5;
    static unsigned long long muTemplateHash = 0xB4708CCEB9DC9B88;

    int miMinSlots;
    float mfMinValueInMillions;
    int miMaxSlots;
    float mfMaxValueInMillions;
    float mfCoolMultiplier;
    float mfTradeInMultiplier;
    cTkFixedArray<float> maClassMultiplier;
}
