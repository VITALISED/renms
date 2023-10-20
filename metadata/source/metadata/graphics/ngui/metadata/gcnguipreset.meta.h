#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>

class cGcNGuiPreset
{
    static unsigned long long muNameHash = 0x31B2A19D40422178;
    static unsigned long long muTemplateHash = 0xB5733CBA8C6D4D8;

    cTkFixedString<128,char> macFont;
    cTkFixedArray<cGcNGuiPresetGraphic> maLayer;
    cTkFixedArray<cGcNGuiPresetGraphic> maGraphic;
    cTkFixedArray<cGcNGuiPresetText> maText;
    cGcNGuiLayoutData SpacingLayout;
}