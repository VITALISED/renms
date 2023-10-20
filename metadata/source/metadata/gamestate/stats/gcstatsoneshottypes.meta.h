#pragma once
#include <metadata/metadata_common.h>
enum eStatsOneShot
{
    EStatsOneShot_ShipLanded = 0,
    EStatsOneShot_ShipLaunched = 1,
    EStatsOneShot_ShipWarped = 2,
    EStatsOneShot_WeaponFired = 3,
}

class cGcStatsOneShotTypes
{
    static unsigned long long muNameHash = 0x32707F0D00335D4F;
    static unsigned long long muTemplateHash = 0x26885B9B57AC27F0;

    eStatsOneShot StatsOneShot;
}
