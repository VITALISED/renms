#pragma once
#include <metadata/metadata_common.h>

class cGcStatIconTable
{
    static unsigned long long muNameHash = 0x266F5269ED2C5661;
    static unsigned long long muTemplateHash = 0x42F48C491DACAEF8;

    cTkFixedArray<cTkFixedString<128,char>> maStatIcons;
}
