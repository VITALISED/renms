#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/stats/gcstatvaluedata.meta.h>

class cGcPlayerStat
{
    static unsigned long long muNameHash = 0x386029983CBEF506;
    static unsigned long long muTemplateHash = 0xAD8326CF9C4340A9;

    TkID<128> mId;
    cGcStatValueData Value;
}
