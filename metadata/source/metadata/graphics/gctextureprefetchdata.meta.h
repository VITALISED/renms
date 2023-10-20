#pragma once
#include <metadata/metadata_common.h>

class cGcTexturePrefetchData
{
    static unsigned long long muNameHash = 0xE2910F7CA28A0271;
    static unsigned long long muTemplateHash = 0xF38ACC62091E1E75;

    cTkDynamicArray<cTkFixedString<128,char>> maTextures;
}
