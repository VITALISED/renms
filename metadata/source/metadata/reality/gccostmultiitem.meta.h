#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcitemamountcostpair.meta.h>

class cGcCostMultiItem
{
    static unsigned long long muNameHash = 0x8753450A435B1BC5;
    static unsigned long long muTemplateHash = 0x20AFBE2273197FD8;

    TkID<256> mDisplayLocID;
    bool mbOnlyTakeIfCanAfford;
    cTkDynamicArray<cGcItemAmountCostPair> maItemList;
}
