#pragma once
#include <metadata/metadata_common.h>

class cGcSentinelSpawnSequenceGroupList
{
    static unsigned long long muNameHash = 0xA4724D07435E3B7C;
    static unsigned long long muTemplateHash = 0x1504D07F20F2659A;

    cTkDynamicArray<TkID<128>> maSequences;
    cTkDynamicArray<TkID<128>> maExtremeSequences;
}
