#pragma once
#include <metadata/metadata_common.h>
enum eStatsAchievements
{
    EStatsAchievements_FirstWarp = 0,
    EStatsAchievements_FirstDiscovery = 1,
}

class cGcStatsAchievements
{
    static unsigned long long muNameHash = 0xADDED46314D20DE5;
    static unsigned long long muTemplateHash = 0x7C4D510DA52511C5;

    eStatsAchievements StatsAchievements;
}
