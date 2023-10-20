#pragma once
#include <metadata/metadata_common.h>
enum eStatsValue
{
    EStatsValue_DistanceJetpacked = 0,
    EStatsValue_DistanceWalked = 1,
    EStatsValue_DistanceWarped = 2,
    EStatsValue_DamageSustained = 3,
}

class cGcStatsValueTypes
{
    static unsigned long long muNameHash = 0x77560873BF71CDAB;
    static unsigned long long muTemplateHash = 0xDE4AB318918F5504;

    eStatsValue StatsValue;
}
