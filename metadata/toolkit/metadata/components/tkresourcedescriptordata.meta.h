#pragma once
#include <metadata/metadata_common.h>

class cTkResourceDescriptorData
{
    static unsigned long long muNameHash = 0xC24CCFE195015403;
    static unsigned long long muTemplateHash = 0x4F8F0561C7986C88;

    TkID<256> mId;
    cTkFixedString<128,char> macName;
    cTkDynamicArray<cTkFixedString<128,char>> maReferencePaths;
    float mfChance;
    cTkDynamicArray<cTkClassPointer> maChildren;
}
