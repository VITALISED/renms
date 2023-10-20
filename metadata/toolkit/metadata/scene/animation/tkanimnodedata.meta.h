#pragma once
#include <metadata/metadata_common.h>

class cTkAnimNodeData
{
    static unsigned long long muNameHash = 0x6E19250A34E2CE86;
    static unsigned long long muTemplateHash = 0x201D028F2C6CBDB7;

    cTkFixedString<64,char> macNode;
    bool mbCanCompress;
    int miRotIndex;
    int miTransIndex;
    int miScaleIndex;
}
