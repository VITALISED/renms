#pragma once
#include <metadata/metadata_common.h>
#include <metadata/graphics/hud/gcfontdata.meta.h>

class cGcFontTable
{
    static unsigned long long muNameHash = 0xD77829A90743F12E;
    static unsigned long long muTemplateHash = 0xF2D00947D92DFB8A;

    cTkFixedArray<cGcFontData> maTable;
}
