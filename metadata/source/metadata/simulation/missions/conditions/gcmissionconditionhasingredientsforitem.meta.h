#pragma once
#include <metadata/metadata_common.h>

class cGcMissionConditionHasIngredientsForItem
{
    static unsigned long long muNameHash = 0x84BBBF70C34631CA;
    static unsigned long long muTemplateHash = 0xF363A7A9323D1D2A;

    cTkDynamicArray<TkID<128>> maTargetItems;
    bool mbRepair;
}
