#pragma once
#include <metadata/metadata_common.h>
enum eItemOutOfBoundsBehaviour
{
    EItemOutOfBoundsBehaviour_NoCost = 0,
    EItemOutOfBoundsBehaviour_UseFirst = 1,
    EItemOutOfBoundsBehaviour_UseLast = 2,
}

class cGcCostItemListIndexed
{
    static unsigned long long muNameHash = 0xA57C34B1B939D649;
    static unsigned long long muTemplateHash = 0x3C8007CCCC34B3A4;

    cTkDynamicArray<TkID<128>> maCosts;
    int miAmount;
    bool mbAssertIfOutOfBounds;
    eItemOutOfBoundsBehaviour ItemOutOfBoundsBehaviour;
    eItemIndexProvider ItemIndexProvider;
}
