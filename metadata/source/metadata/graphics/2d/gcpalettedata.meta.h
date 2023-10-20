#pragma once
#include <metadata/metadata_common.h>
enum eNumColours
{
    ENumColours_Inactive = 0,
    ENumColours_1 = 1,
    ENumColours_4 = 2,
    ENumColours_8 = 3,
    ENumColours_16 = 4,
    ENumColours_All = 5,
}

class cGcPaletteData
{
    static unsigned long long muNameHash = 0xB66F8D60603D1092;
    static unsigned long long muTemplateHash = 0x9DFAC1F6DF6F3F6A;

    eNumColours NumColours;
    cTkFixedArray<cTkColour> maColours;
}
