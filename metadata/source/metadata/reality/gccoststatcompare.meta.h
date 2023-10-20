#pragma once
#include <metadata/metadata_common.h>

class cGcCostStatCompare
{
    static unsigned long long muNameHash = 0xA889775D93694AA7;
    static unsigned long long muTemplateHash = 0xDBD0090BB16E436E;

    TkID<128> mCoreStat;
    TkID<128> mCompareAndSetStat;
    TkID<256> mCostStringCanAfford;
    TkID<256> mCostStringCantAfford;
}
