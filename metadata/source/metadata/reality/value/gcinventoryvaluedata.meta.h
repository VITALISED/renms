#pragma once
#include <metadata/metadata_common.h>

class cGcInventoryValueData
{
    static unsigned long long muNameHash = 0x9118F575B23083D9;
    static unsigned long long muTemplateHash = 0xA08FF46B3C4DECBB;

    float mfBaseMinValue;
    float mfBaseMaxValue;
    float mfExponentialValue;
    float mfBaseCostPerSlot;
    float mfSlotExponentialValue;
    float mfValueToCost;
    float mfSlotsPerLevel;
}
