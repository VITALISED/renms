#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcScanEventTable
{
    static unsigned long long muNameHash = 0xD550A58E83EA253;
    static unsigned long long muTemplateHash = 0x89568DF828C00FD0;

    cTkDynamicArray<cGcScanEventData> maEvents;
}
