#pragma once
#include <metadata/metadata_common.h>

class cTkAnimJointLODData
{
    static unsigned long long muNameHash = 0x6316491205B3FC32;
    static unsigned long long muTemplateHash = 0x9EB487CAB4D10F3F;

    int miLOD;
    cTkDynamicArray<cTkFixedString<64,char>> maJointNames;
}
