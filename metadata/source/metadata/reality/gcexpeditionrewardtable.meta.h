#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcgenericrewardtableentry.meta.h>

class cGcExpeditionRewardTable
{
    static unsigned long long muNameHash = 0xDFC93B6F3652FDE5;
    static unsigned long long muTemplateHash = 0x135A33E156FC104A;

    cTkDynamicArray<cGcGenericRewardTableEntry> maTable;
}
