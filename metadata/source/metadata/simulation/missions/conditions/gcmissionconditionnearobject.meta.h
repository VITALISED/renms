#pragma once
#include <metadata/metadata_common.h>
enum eMissionObject
{
    EMissionObject_PlayerShip = 0,
    EMissionObject_PlayerVehicle = 1,
    EMissionObject_StoryPortal = 2,
    EMissionObject_OpenStandardPortal = 3,
}

class cGcMissionConditionNearObject
{
    static unsigned long long muNameHash = 0x748605335FA1C427;
    static unsigned long long muTemplateHash = 0x98A8088CCBCB2360;

    eMissionObject MissionObject;
    float mfDistance;
}
