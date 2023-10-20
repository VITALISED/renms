#pragma once
#include <metadata/metadata_common.h>

class cGcNGuiFileBrowserRecents
{
    static unsigned long long muNameHash = 0x1683B0270AE180;
    static unsigned long long muTemplateHash = 0xBA4458954448454D;

    cTkFixedArray<cTkFixedString<256,char>> maRecents;
}
