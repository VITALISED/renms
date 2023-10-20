#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcproceduralproductdata.meta.h>

class cGcProceduralProductTable
{
    static unsigned long long muNameHash = 0x9A0073340429C464;
    static unsigned long long muTemplateHash = 0x6793591DE3B10D2B;

    cTkFixedArray<cGcProceduralProductData> maTable;
}
