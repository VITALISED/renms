#pragma once
#include <metadata/metadata_common.h>
#include <metadata/graphics/2d/gccolourpalettedata.meta.h>

class cGcPlanetColourData
{
    static unsigned long long muNameHash = 0x555E177C27F47DDB;
    static unsigned long long muTemplateHash = 0x36075EC9FFF35F73;

    cTkFixedArray<cGcColourPaletteData> maPalettes;
}
