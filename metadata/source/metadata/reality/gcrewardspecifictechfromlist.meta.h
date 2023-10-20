#pragma once
#include <metadata/metadata_common.h>
enum eTechListRewardOrder
{
    ETechListRewardOrder_OneRandom = 0,
    ETechListRewardOrder_InOrder = 1,
    ETechListRewardOrder_TryAllRandom = 2,
}

class cGcRewardSpecificTechFromList
{
    static unsigned long long muNameHash = 0xF33640B1865E5E4B;
    static unsigned long long muTemplateHash = 0xF5958A51F9612CFB;

    cTkDynamicArray<TkID<128>> maTechList;
    bool mbFailIfAllKnown;
    eTechListRewardOrder TechListRewardOrder;
}
