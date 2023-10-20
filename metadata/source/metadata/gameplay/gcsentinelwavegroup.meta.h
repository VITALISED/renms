#pragma once
#include <metadata/metadata_common.h>

class cGcSentinelWaveGroup
{
    static unsigned long long muNameHash = 0xE866662BD040EDFB;
    static unsigned long long muTemplateHash = 0xAD3F352CAAE1C6AA;

    cTkDynamicArray<TkID<128>> maWaves;
    cTkDynamicArray<TkID<128>> maExtremeWaves;
}
