#pragma once
#include <metadata/metadata_common.h>

class cTkLSystemGlobalVariation
{
    static unsigned long long muNameHash = 0xF818362C38FEA359;
    static unsigned long long muTemplateHash = 0x90BB4D028350EF77;

    cTkFixedString<32,char> macName;
    cTkFixedString<128,char> macModel;
    int miVariations;
}
