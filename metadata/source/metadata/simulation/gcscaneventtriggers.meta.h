#pragma once
#include <metadata/metadata_common.h>

class cGcScanEventTriggers
{
    static unsigned long long muNameHash = 0x6F214CFBE5603A0;
    static unsigned long long muTemplateHash = 0xCEF281A467E57BEF;

    float mfRange;
    cTkDynamicArray<TkID<128>> maTriggers;
    bool mbAllowRetrigger;
}
