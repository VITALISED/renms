#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceStop
{
    static unsigned long long muNameHash = 0x9B3472E4293AC465;
    static unsigned long long muTemplateHash = 0x1986E7CCD49F9CDF;

    cTkFixedString<128,char> macMessage;
    cTkFixedString<128,char> macDebugText;
}
