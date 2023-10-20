#pragma once
#include <metadata/metadata_common.h>

class cGcColourPaletteData
{
    static unsigned long long muNameHash = 0x3F4922910DCC54BD;
    static unsigned long long muTemplateHash = 0x99579791A89F2068;

    cTkFixedArray<cTkColour> maColours;
    cTkFixedArray<int> maColourIndices;
}
