#pragma once
#include <metadata/metadata_common.h>
enum eGalaxyWaypointType
{
    EGalaxyWaypointType_User = 0,
    EGalaxyWaypointType_Gameplay_AtlasStation = 1,
    EGalaxyWaypointType_Gameplay_DistressBeacon = 2,
    EGalaxyWaypointType_Gameplay_BlackHole = 3,
    EGalaxyWaypointType_Gameplay_Mission = 4,
    EGalaxyWaypointType_Gameplay_SeasonParty = 5,
}

class cGcGalaxyWaypointTypes
{
    static unsigned long long muNameHash = 0xF808614547AF2B25;
    static unsigned long long muTemplateHash = 0x35632D9AFE0F476F;

    eGalaxyWaypointType GalaxyWaypointType;
}
