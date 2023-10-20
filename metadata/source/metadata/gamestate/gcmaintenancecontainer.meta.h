#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/gcinventorycontainer.meta.h>

class cGcMaintenanceContainer
{
    static unsigned long long muNameHash = 0x4AF1E9D7AD4CC1C7;
    static unsigned long long muTemplateHash = 0xEF4B1C508C663D7;

    cGcInventoryContainer InventoryContainer;
    unsigned long long mui64LastUpdateTimestamp;
    unsigned long long mui64LastCompletedTimestamp;
    unsigned long long mui64LastBrokenTimestamp;
    cTkDynamicArray<float> maDamageTimers;
    cTkDynamicArray<float> maAmountAccumulators;
    unsigned short muiFlags;
}
