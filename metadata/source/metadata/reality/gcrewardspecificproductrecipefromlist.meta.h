#pragma once
#include <metadata/metadata_common.h>
enum eProductListRewardOrder
{
    EProductListRewardOrder_OneRandom = 0,
    EProductListRewardOrder_InOrder = 1,
    EProductListRewardOrder_TryAllRandom = 2,
    EProductListRewardOrder_TryUnknownRandom = 3,
}

class cGcRewardSpecificProductRecipeFromList
{
    static unsigned long long muNameHash = 0xCD501C8D037C74A5;
    static unsigned long long muTemplateHash = 0x70D4DBB1996C8F42;

    cTkDynamicArray<TkID<128>> maProductList;
    eProductListRewardOrder ProductListRewardOrder;
}
