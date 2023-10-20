#pragma once
#include <metadata/metadata_common.h>
enum eFont
{
    EFont_Impact = 0,
    EFont_Bebas = 1,
    EFont_GeosansLightWide = 2,
    EFont_GeosansLight = 3,
    EFont_GeosansLightMedium = 4,
    EFont_GeosansLightSmall = 5,
    EFont_Segoeuib = 6,
    EFont_Segoeui32 = 7,
}

class cGcFontTypesEnum
{
    static unsigned long long muNameHash = 0xDD7598814880C206;
    static unsigned long long muTemplateHash = 0x32669E5C63E0E597;

    eFont Font;
}
