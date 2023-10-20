#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcPlayerStatsGroup
{
    static unsigned long long muNameHash = 0xEBAB39E2F49FE5F;
    static unsigned long long muTemplateHash = 0xD0E298116C7E223F;

    TkID<128> mGroupId;
    unsigned long long mui64Address;
    cTkDynamicArray<cGcPlayerStat> maStats;
}
