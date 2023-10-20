#pragma once
#include <metadata/metadata_common.h>
enum eScanEventTable
{
    EScanEventTable_Space = 0,
    EScanEventTable_Planet = 1,
    EScanEventTable_Missions = 2,
    EScanEventTable_Tutorial = 3,
    EScanEventTable_MissionsCreative = 4,
    EScanEventTable_NPCPlanetSite = 5,
}

class cGcRewardScanEvent
{
    static unsigned long long muNameHash = 0xD6D2BF5DDCCD9F49;
    static unsigned long long muTemplateHash = 0x1AB044C825466554;

    TkID<256> mEvent;
    eScanEventTable ScanEventTable;
    bool mbDoAerialScan;
    bool mbUseMissionSeedForEvent;
    float mfStartDelay;
    bool mbUseStartDelayWhenNoAerialScan;
}
