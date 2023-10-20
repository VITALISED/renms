#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/reward/gcrewardtableitemlist.meta.h>

class cGcGenericRewardTableEntry
{
    static unsigned long long muNameHash = 0xB457288101712FB5;
    static unsigned long long muTemplateHash = 0xFAD30401E6E327C4;

    TkID<128> mId;
    cGcRewardTableItemList List;
}
