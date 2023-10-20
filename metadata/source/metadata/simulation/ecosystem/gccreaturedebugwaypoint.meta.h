#pragma once
#include <metadata/metadata_common.h>
enum eWaypointType
{
    EWaypointType_Move = 0,
    EWaypointType_MoveAlt = 1,
    EWaypointType_Idle = 2,
}

class cGcCreatureDebugWaypoint
{
    static unsigned long long muNameHash = 0x4C03886F1A1C1DF7;
    static unsigned long long muTemplateHash = 0xACAF195392879AE9;

    cTkVector3 mPosition;
    eWaypointType WaypointType;
    TkID<128> mAnim;
    float mfTime;
}
