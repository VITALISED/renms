#pragma once
#include <metadata/metadata_common.h>

class cGcShipHUDTargetIconData
{
    static unsigned long long muNameHash = 0xFAC452E6BECE8553;
    static unsigned long long muTemplateHash = 0x3E1BAB2D23187208;

    cTkFixedString<128,char> macCorner;
    cTkFixedString<128,char> macLineHorizontal;
    cTkFixedString<128,char> macLineVertical;
    cTkFixedString<128,char> macGlowCorner;
    cTkFixedString<128,char> macGlowLineHorizontal;
    cTkFixedString<128,char> macGlowLineVertical;
}
