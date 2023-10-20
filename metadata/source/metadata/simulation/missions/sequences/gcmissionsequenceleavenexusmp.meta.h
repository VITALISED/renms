#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceLeaveNexusMP
{
    static unsigned long long muNameHash = 0x210E5E8D593FFE;
    static unsigned long long muTemplateHash = 0x6D3A4695659CC613;

    cTkFixedString<128,char> macMessage;
    cTkFixedString<128,char> macMessageNoWarp;
    unsigned long long mui64Timeout;
    cTkFixedString<128,char> macDebugText;
}
