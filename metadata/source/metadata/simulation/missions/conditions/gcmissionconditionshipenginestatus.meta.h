#pragma once
#include <metadata/metadata_common.h>
enum eEngineStatus
{
    EEngineStatus_Thrusting = 0,
    EEngineStatus_Braking = 1,
    EEngineStatus_Landing = 2,
    EEngineStatus_Landed = 3,
    EEngineStatus_Boosting = 4,
    EEngineStatus_Pulsing = 5,
    EEngineStatus_LowFlight = 6,
    EEngineStatus_Inverted = 7,
}

class cGcMissionConditionShipEngineStatus
{
    static unsigned long long muNameHash = 0x9A43A9B870251F8C;
    static unsigned long long muTemplateHash = 0x39385853D394BC7C;

    eEngineStatus EngineStatus;
}
