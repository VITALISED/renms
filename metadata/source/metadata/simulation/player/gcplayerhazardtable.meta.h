#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/player/gcplayerhazarddata.meta.h>

class cGcPlayerHazardTable
{
    static unsigned long long muNameHash = 0xCC978CCE3CFE915B;
    static unsigned long long muTemplateHash = 0xE733D394BDB2C23A;

    cTkFixedArray<cGcPlayerHazardData> maTable;
}
