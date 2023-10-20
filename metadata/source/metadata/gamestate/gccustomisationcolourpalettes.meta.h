#pragma once
#include <metadata/metadata_common.h>
#include <metadata/graphics/2d/gcpalettedata.meta.h>
#include <metadata/gamestate/gccustomisationcolourpaletteextradata.meta.h>

class cGcCustomisationColourPalettes
{
    static unsigned long long muNameHash = 0x8D353F7BD3E655C5;
    static unsigned long long muTemplateHash = 0xEBEFF3A4D2A4DE2B;

    cTkFixedArray<cGcPaletteData> maColourPalettes;
    cTkFixedArray<cGcCustomisationColourPaletteExtraData> maExtraData;
}
