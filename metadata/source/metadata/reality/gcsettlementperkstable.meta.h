#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcsettlementperkdata.meta.h>

class cGcSettlementPerksTable
{
    static unsigned long long muNameHash = 0x3FBCD98A534164CD;
    static unsigned long long muTemplateHash = 0x6209FDB2A1124E2;

    cTkDynamicArray<cGcSettlementPerkData> maTable;
}
