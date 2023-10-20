#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcNGuiTextData
{
    static unsigned long long muNameHash = 0x4C5F02B93CB08B1A;
    static unsigned long long muTemplateHash = 0x399A33599C8EC1D3;

    cGcNGuiElementData ElementData;
    cTkNGuiTextStyle Style;
    cTkNGuiGraphicStyle GraphicStyle;
    cTkFixedString<512,char> macText;
    cTkFixedString<128,char> macImage;
    float mfForcedOffset;
    cTkDynamicArray<cGcVROverride_Text> maVROverrides;
    cTkDynamicArray<cGcAccessibleOverride_Text> maAccessibleOverrides;
    bool mbSpecial;
    bool mbForcedAllowScroll;
}
