#pragma once
#include <metadata/metadata_common.h>

class cGcDiscoveryRewardLookup
{
    static unsigned long long muNameHash = 0xA2280C1D273E7644;
    static unsigned long long muTemplateHash = 0x214EA4354D0DD100;

    TkID<128> mId;
    TkID<128> mSecondary;
    cTkFixedArray<TkID<128>> maBiomeSpecific;
}
