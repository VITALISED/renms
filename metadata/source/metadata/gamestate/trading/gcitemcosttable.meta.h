#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcitemcostdata.meta.h>

class cGcItemCostTable
{
    static unsigned long long muNameHash = 0xF3A6F2D8DFF9DF48;
    static unsigned long long muTemplateHash = 0x360988B36BBAF201;

    cTkDynamicArray<cGcItemCostData> maItems;
}
