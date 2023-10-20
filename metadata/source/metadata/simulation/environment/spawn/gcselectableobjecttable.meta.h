#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/environment/spawn/gcselectableobjectlist.meta.h>

class cGcSelectableObjectTable
{
    static unsigned long long muNameHash = 0xCE1983E849879238;
    static unsigned long long muTemplateHash = 0x52E360F0EF0B1133;

    cTkDynamicArray<cGcSelectableObjectList> maLists;
}
