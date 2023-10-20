#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/stats/gcstatgroupdata.meta.h>

class cGcStatGroupTable
{
    static unsigned long long muNameHash = 0xE07E83B8A167074C;
    static unsigned long long muTemplateHash = 0x2885A5C8155BCEB0;

    cTkDynamicArray<cGcStatGroupData> maGcStatGroupTable;
}
