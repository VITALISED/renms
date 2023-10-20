#pragma once
#include <metadata/metadata_common.h>

class cGcNGuiSpecialTextImageData
{
    static unsigned long long muNameHash = 0xF594D54B778D6517;
    static unsigned long long muTemplateHash = 0x7026F5C51A6E08D0;

    TkID<128> mName;
    bool mbScaleToFitFont;
    cTkVector2 mSize;
    cTkFixedString<128,char> macPath;
}
