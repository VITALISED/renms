#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcFrigateStats
{
    static unsigned long long muNameHash = 0x38BD9FF11F2B46AB;
    static unsigned long long muTemplateHash = 0x59270EF7B973C889;

    cTkFixedArray<cGcFrigateStatRange> maStats;
    TkID<128> mInitialTrait;
}
