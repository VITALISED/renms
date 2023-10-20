#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cTkProceduralTextureChosenOption
{
    static unsigned long long muNameHash = 0x4BFAC826445A23F2;
    static unsigned long long muTemplateHash = 0xEF693901D9F148D0;

    TkID<128> mLayer;
    TkID<128> mGroup;
    cTkPaletteTexture Palette;
    bool mbOverrideColour;
    cTkColour mColour;
    TkID<256> mOptionName;
}
