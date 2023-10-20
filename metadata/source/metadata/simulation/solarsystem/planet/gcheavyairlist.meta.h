#pragma once
#include <metadata/metadata_common.h>

class cGcHeavyAirList
{
    static unsigned long long muNameHash = 0xFAC8C84FEF536E3;
    static unsigned long long muTemplateHash = 0x42B96E6C683A52C7;

    cTkDynamicArray<cTkFixedString<128,char>> maOptions;
}
