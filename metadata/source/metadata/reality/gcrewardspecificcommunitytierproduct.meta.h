#pragma once
#include <metadata/metadata_common.h>

class cGcRewardSpecificCommunityTierProduct
{
    static unsigned long long muNameHash = 0xA0372351D829A5B0;
    static unsigned long long muTemplateHash = 0xED9C5204B538EF2E;

    cTkDynamicArray<TkID<128>> maProductList;
    int miAmountMin;
    int miAmountMax;
    bool mbForceSpecialMessage;
    TkID<128> mRequiresTech;
}
