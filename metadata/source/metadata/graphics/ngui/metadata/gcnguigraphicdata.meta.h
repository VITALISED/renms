#pragma once
#include <metadata/metadata_common.h>
#include <metadata/graphics/ngui/metadata/gcnguielementdata.meta.h>
#include <metadata/ngui/tknguigraphicstyle.meta.h>

class cGcNGuiGraphicData
{
    static unsigned long long muNameHash = 0x264B878043DA20B3;
    static unsigned long long muTemplateHash = 0xFA260C4B6F9A60E0;

    cGcNGuiElementData ElementData;
    cTkNGuiGraphicStyle Style;
    cTkFixedString<128,char> macImage;
}
