#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceGetUnits
{
    static unsigned long long muNameHash = 0x785DA5C6069D4C12;
    static unsigned long long muTemplateHash = 0x2B06EC7C0037A048;

    cTkFixedString<128,char> macMessage;
    int miAmount;
    cTkFixedString<128,char> macDebugText;
}
