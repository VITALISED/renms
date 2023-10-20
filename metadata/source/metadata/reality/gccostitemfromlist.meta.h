#pragma once
#include <metadata/metadata_common.h>

class cGcCostItemFromList
{
    static unsigned long long muNameHash = 0xD9C971EFC16BB550;
    static unsigned long long muTemplateHash = 0x3CFA999F9B2E42A4;

    int miAmount;
    cTkDynamicArray<TkID<128>> maItemList;
    int miIndex;
}
