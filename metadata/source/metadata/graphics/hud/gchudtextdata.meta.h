#pragma once
#include <metadata/metadata_common.h>
#include <metadata/graphics/hud/gchudcomponent.meta.h>
#include <metadata/graphics/hud/gctextpreset.meta.h>

class cGcHUDTextData
{
    static unsigned long long muNameHash = 0x88CFB7D1D223D0C5;
    static unsigned long long muTemplateHash = 0x8EF3CBDD0A950DED;

    cGcHUDComponent Data;
    cTkFixedString<128,char> macText;
    cGcTextPreset Preset;
}
