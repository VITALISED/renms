#pragma once
#include <metadata/metadata_common.h>

class cGcCreatureStupidName
{
    static unsigned long long muNameHash = 0x7754E453D7160CA6;
    static unsigned long long muTemplateHash = 0xB254424D362E8BE7;

    TkID<128> mId;
    int miCount;
    cTkDynamicArray<cTkFixedString<128,char>> maNames;
}
