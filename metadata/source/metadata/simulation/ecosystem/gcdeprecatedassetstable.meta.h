#pragma once
#include <metadata/metadata_common.h>

class cGcDeprecatedAssetsTable
{
    static unsigned long long muNameHash = 0x6F0E264357FD693D;
    static unsigned long long muTemplateHash = 0x26B598C2ECD1F4F0;

    cTkDynamicArray<cTkFixedString<128,char>> maTable;
}
