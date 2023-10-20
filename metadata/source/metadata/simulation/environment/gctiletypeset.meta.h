#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tkpalettetexture.meta.h>

class cGcTileTypeSet
{
    static unsigned long long muNameHash = 0x30CD85DD787F512A;
    static unsigned long long muTemplateHash = 0xDAFAD9D4B84F95B7;

    float mfProbability;
    cTkFixedArray<cTkPaletteTexture> maColours;
}
