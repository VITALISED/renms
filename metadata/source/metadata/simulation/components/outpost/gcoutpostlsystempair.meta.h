#pragma once
#include <metadata/metadata_common.h>

class cGcOutpostLSystemPair
{
    static unsigned long long muNameHash = 0x3C7F32FAD34D5752;
    static unsigned long long muTemplateHash = 0x5648049D69F3A0BB;

    cTkFixedString<32,char> macLocator;
    cTkFixedArray<cTkFixedString<128,char>> maLSystems;
}
