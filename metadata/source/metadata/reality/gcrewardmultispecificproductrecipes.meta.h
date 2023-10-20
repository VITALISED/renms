#pragma once
#include <metadata/metadata_common.h>

class cGcRewardMultiSpecificProductRecipes
{
    static unsigned long long muNameHash = 0x3FF01CECDEAECD1D;
    static unsigned long long muTemplateHash = 0xA55F427D92D5310B;

    cTkDynamicArray<TkID<128>> maProductIds;
    TkID<128> mDisplayProductId;
    TkID<256> mSetName;
    bool mbSilent;
}
