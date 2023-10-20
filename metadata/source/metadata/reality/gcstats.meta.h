#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcstatsgroup.meta.h>

class cGcStats
{
    static unsigned long long muNameHash = 0x9C20970E839B65D9;
    static unsigned long long muTemplateHash = 0xC0383134FAEA1198;

    cTkDynamicArray<cGcStatsGroup> maStats;
}
