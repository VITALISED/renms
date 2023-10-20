#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/customisation/gccustomisationbannerimagedata.meta.h>
#include <metadata/graphics/2d/gcpalettedata.meta.h>
#include <metadata/gamestate/gccustomisationcolourpaletteextradata.meta.h>

class cGcCustomisationBannerGroup
{
    static unsigned long long muNameHash = 0xD679E7C47BC9313C;
    static unsigned long long muTemplateHash = 0xA9D290FD12C9A030;

    cTkDynamicArray<cGcCustomisationBannerImageData> maBannerImages;
    cGcPaletteData MainColours;
    cGcCustomisationColourPaletteExtraData MainColoursExtraData;
    cGcPaletteData BackgroundColours;
    cGcCustomisationColourPaletteExtraData BackgroundColoursExtraData;
}
