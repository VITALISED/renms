#pragma once
#include <metadata/metadata_common.h>

class cGcBootLogoData
{
    static unsigned long long muNameHash = 0x1667364CB586EB42;
    static unsigned long long muTemplateHash = 0x87DB90412F957DEF;

    cTkFixedArray<cTkFixedString<256,char>> maTextures;
    cTkFixedArray<float> maDisplayTime;
}
