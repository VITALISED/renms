#pragma once
#include <metadata/metadata_common.h>
enum eScanTable
{
    EScanTable_Space = 0,
    EScanTable_Planet  = 1,
    EScanTable_Missions = 2,
    EScanTable_Tutorial = 3,
    EScanTable_MissionsCreative = 4,
    EScanTable_Vehicle = 5,
    EScanTable_NPCPlanetSite = 6,
    EScanTable_Seasonal = 7,
}

class cGcScanEventTableType
{
    static unsigned long long muNameHash = 0x34D109FC6FD5709;
    static unsigned long long muTemplateHash = 0x1815B0A103BF81B7;

    eScanTable ScanTable;
}
