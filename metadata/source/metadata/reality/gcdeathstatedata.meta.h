#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcdeathquote.meta.h>
#include <metadata/graphics/hud/gctextpreset.meta.h>

class cGcDeathStateData
{
    static unsigned long long muNameHash = 0x5B824AD343C4561E;
    static unsigned long long muTemplateHash = 0x5EC2AD5973679FDE;

    cTkDynamicArray<cGcDeathQuote> maQuotes;
    cGcTextPreset ReasonFont;
    cGcTextPreset QuoteFont;
    cGcTextPreset AuthorFont;
}
