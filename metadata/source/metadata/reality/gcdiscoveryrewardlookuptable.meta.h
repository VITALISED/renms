#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcdiscoveryrewardlookup.meta.h>

class cGcDiscoveryRewardLookupTable
{
    static unsigned long long muNameHash = 0x9160051E7F0A1295;
    static unsigned long long muTemplateHash = 0xB17F47EC34A52218;

    cTkDynamicArray<cGcDiscoveryRewardLookup> maTable;
}
