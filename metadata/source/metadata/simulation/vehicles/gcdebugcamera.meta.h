#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/vehicles/gcdebugcameraentry.meta.h>

class cGcDebugCamera
{
    static unsigned long long muNameHash = 0xC7724B26F8E50BC5;
    static unsigned long long muTemplateHash = 0x4115B5E6806757B5;

    float mfBaseSpeed;
    float mfSmoothing;
    cTkDynamicArray<cGcDebugCameraEntry> maWaypoints;
    int miCurrentWaypoint;
    float mfCurrentWaypointProgress;
}
