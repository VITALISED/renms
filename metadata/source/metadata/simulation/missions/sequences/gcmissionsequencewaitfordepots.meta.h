#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceWaitForDepots
{
    static unsigned long long muNameHash = 0x79D85DCF556B9E6B;
    static unsigned long long muTemplateHash = 0x84148783106D2CB8;

    cTkFixedString<128,char> macMessage;
    int miAmountMin;
    int miAmountMax;
    cTkFixedString<128,char> macDebugText;
}
