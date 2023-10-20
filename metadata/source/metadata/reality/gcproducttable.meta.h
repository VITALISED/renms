#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcproductdata.meta.h>

class cGcProductTable
{
    static unsigned long long muNameHash = 0x7A62ED648FC514F7;
    static unsigned long long muTemplateHash = 0x4815B0C33757F951;

    cTkDynamicArray<cGcProductData> maTable;
}
