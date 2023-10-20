#pragma once
#include <metadata/metadata_common.h>
enum eScanType
{
    EScanType_Tool = 0,
    EScanType_Beacon = 1,
    EScanType_RadioTower = 2,
    EScanType_Observatory = 3,
    EScanType_DistressSignal = 4,
    EScanType_Waypoint = 5,
    EScanType_Ship = 6,
    EScanType_DebugPlanet = 7,
    EScanType_DebugSpace = 8,
    EScanType_VisualOnly = 9,
    EScanType_VisualOnlyAerial = 10,
}

class cGcScanData
{
    static unsigned long long muNameHash = 0x8531B20A02DD0931;
    static unsigned long long muTemplateHash = 0x10D41904DB6F3321;

    eScanType ScanType;
    float mfPulseRange;
    float mfPulseTime;
    bool mbPlayAudioOnMarkers;
    float mfChargeTime;
}
