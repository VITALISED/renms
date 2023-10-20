#pragma once
#include <metadata/metadata_common.h>
#include <metadata/ngui/tknguieditorstylecolour.meta.h>
#include <metadata/ngui/tknguigraphicstyle.meta.h>
#include <metadata/ngui/tknguitextstyle.meta.h>

class cTkNGuiEditorStyleData
{
    static unsigned long long muNameHash = 0x6F26BF19981BB60C;
    static unsigned long long muTemplateHash = 0x8FA7BC8A7836C20;

    cTkFixedArray<float> maSizes;
    cTkFixedArray<cTkNGuiEditorStyleColour> maSkinColours;
    float mfSkinFontHeight;
    cTkFixedString<128,char> macFont;
    cTkFixedArray<cTkNGuiGraphicStyle> maGraphicStyles;
    cTkFixedArray<cTkNGuiTextStyle> maTextStyles;
    cTkDynamicArray<float> maSnapSettings;
}
