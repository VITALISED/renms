#pragma once
#include <metadata/metadata_common.h>
enum eGalaxyMarkerType
{
    EGalaxyMarkerType_StartingLocation = 0,
    EGalaxyMarkerType_Home = 1,
    EGalaxyMarkerType_Waypoint = 2,
    EGalaxyMarkerType_Contact = 3,
    EGalaxyMarkerType_Blackhole = 4,
    EGalaxyMarkerType_AtlasStation = 5,
    EGalaxyMarkerType_Selection = 6,
    EGalaxyMarkerType_PlanetBase = 7,
    EGalaxyMarkerType_Visited = 8,
    EGalaxyMarkerType_ScanEvent = 9,
    EGalaxyMarkerType_Expedition = 10,
    EGalaxyMarkerType_NetworkPlayer = 11,
    EGalaxyMarkerType_Freighter = 12,
    EGalaxyMarkerType_PathIcon = 13,
    EGalaxyMarkerType_SeasonParty = 14,
    EGalaxyMarkerType_Settlement = 15,
}

class cGcGalaxyMarkerTypes
{
    static unsigned long long muNameHash = 0x29324EF951272232;
    static unsigned long long muTemplateHash = 0x7B7270127FD40BB2;

    eGalaxyMarkerType GalaxyMarkerType;
}
