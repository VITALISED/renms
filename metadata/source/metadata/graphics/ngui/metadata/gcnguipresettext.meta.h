#pragma once
#include <metadata/metadata_common.h>
#include <metadata/graphics/ngui/metadata/gcnguilayoutdata.meta.h>
#include <metadata/ngui/tknguitextstyle.meta.h>
#include <metadata/ngui/tknguigraphicstyle.meta.h>

class cGcNGuiPresetText
{
    static unsigned long long muNameHash = 0x633D54FB94B2C6A4;
    static unsigned long long muTemplateHash = 0x8C61BE7015E84E93;

    TkID<128> mPresetID;
    cGcNGuiLayoutData Layout;
    cTkNGuiTextStyle Style;
    cTkNGuiGraphicStyle GraphicStyle;
    cTkFixedString<128,char> macImage;
}
