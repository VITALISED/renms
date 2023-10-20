#pragma once
#include <metadata/metadata_common.h>

class cTkMetadataFilenameList
{
    static unsigned long long muNameHash = 0x3F42E6C415489AAF;
    static unsigned long long muTemplateHash = 0xCF02F7B7FB501FAB;

    cTkDynamicArray<cTkFixedString<128,char>> maFilenames;
}
