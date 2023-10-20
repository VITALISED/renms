#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcinventorylayoutgenerationdataentry.meta.h>

class cGcInventoryLayoutGenerationData
{
    static unsigned long long muNameHash = 0x7AA76AD6E14A0C29;
    static unsigned long long muTemplateHash = 0xB88CD25A12DE1832;

    cTkFixedArray<cGcInventoryLayoutGenerationDataEntry> maGenerationDataPerSizeType;
}
