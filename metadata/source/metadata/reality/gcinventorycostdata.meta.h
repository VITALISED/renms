#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcinventorycostdataentry.meta.h>

class cGcInventoryCostData
{
    static unsigned long long muNameHash = 0x891585A60DC0D014;
    static unsigned long long muTemplateHash = 0xC803336C99E965D9;

    cTkFixedArray<cGcInventoryCostDataEntry> maInventoryCostData;
}
