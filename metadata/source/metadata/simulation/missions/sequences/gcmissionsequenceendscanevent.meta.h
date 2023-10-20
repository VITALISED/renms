#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceEndScanEvent
{
    static unsigned long long muNameHash = 0xD15F5E0AAE5AA74;
    static unsigned long long muTemplateHash = 0x593EBE192457373A;

    TkID<256> mEvent;
    cTkFixedString<128,char> macDebugText;
}
