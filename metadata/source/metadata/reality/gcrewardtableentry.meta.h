#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcrewardtablecategory.meta.h>

class cGcRewardTableEntry
{
    static unsigned long long muNameHash = 0x29C1A8399A70F9A7;
    static unsigned long long muTemplateHash = 0xFAD7013839A1D08E;

    TkID<128> mId;
    cTkFixedArray<cGcRewardTableCategory> maRarities;
}
