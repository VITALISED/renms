#pragma once
#include <metadata/metadata_common.h>
#include <metadata/wiki/gcwikicategory.meta.h>

class cGcWiki
{
    static unsigned long long muNameHash = 0x1037140D8873D8ED;
    static unsigned long long muTemplateHash = 0xE20F6F7CAB48E960;

    cTkDynamicArray<cGcWikiCategory> maCategories;
}
