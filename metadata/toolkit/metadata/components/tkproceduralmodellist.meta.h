#pragma once
#include <metadata/metadata_common.h>

class cTkProceduralModelList
{
    static unsigned long long muNameHash = 0xD2657A8AE39E6E61;
    static unsigned long long muTemplateHash = 0x75B1338A1741B7FD;

    TkID<128> mId;
    cTkDynamicArray<cTkFixedString<128,char>> maList;
}
