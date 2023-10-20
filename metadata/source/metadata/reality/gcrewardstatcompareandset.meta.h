#pragma once
#include <metadata/metadata_common.h>

class cGcRewardStatCompareAndSet
{
    static unsigned long long muNameHash = 0x63E76E3324C90001;
    static unsigned long long muTemplateHash = 0x9C43DBC2D460E56A;

    TkID<128> mCoreStat;
    TkID<128> mCompareAndSetStat;
}
