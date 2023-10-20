#pragma once
#include <metadata/metadata_common.h>

class cTkIdArray
{
    static unsigned long long muNameHash = 0x5BE759AC75174BE6;
    static unsigned long long muTemplateHash = 0x428553BDCE6FB2E2;

    cTkDynamicArray<TkID<128>> maArray;
}
