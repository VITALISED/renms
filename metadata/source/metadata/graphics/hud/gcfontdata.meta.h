#pragma once
#include <metadata/metadata_common.h>

class cGcFontData
{
    static unsigned long long muNameHash = 0x1297324AF39B5F4E;
    static unsigned long long muTemplateHash = 0x7119B895413DD133;

    cTkFixedString<128,char> macFile;
    int miMinCharWidth;
}
