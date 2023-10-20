#pragma once
#include <metadata/metadata_common.h>
#include <?>
enum eOnComplete
{
    EOnComplete_Hold = 0,
    EOnComplete_Loop = 1,
    EOnComplete_Destroy = 2,
}

class cGcCreatureDebugSpawnData
{
    static unsigned long long muNameHash = 0x5995CC3B21976698;
    static unsigned long long muTemplateHash = 0x4804062C877D7175;

    int miCreatureIndex;
    float mfInitialDelay;
    cTkDynamicArray<cGcCreatureDebugWaypoint> maWaypoints;
    eOnComplete OnComplete;
    float mfSmoothTime;
    int miCurrentWaypoint;
    bool mbArrivedAtCurrentWaypoint;
    float mfTimer;
    float mfSmoothTimer;
}
