#pragma once
#include <metadata/metadata_common.h>

class cGcItemAmountCostPair
{
    static unsigned long long muNameHash = 0x320CEBDAD440CF79;
    static unsigned long long muTemplateHash = 0x421EA82CA84FCD49;

    TkID<128> mItemId;
    int miAmount;
}
