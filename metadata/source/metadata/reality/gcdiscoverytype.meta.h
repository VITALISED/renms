#pragma once
#include <metadata/metadata_common.h>
enum eDiscoveryType
{
    EDiscoveryType_Unknown = 0,
    EDiscoveryType_SolarSystem = 1,
    EDiscoveryType_Planet = 2,
    EDiscoveryType_Animal = 3,
    EDiscoveryType_Flora = 4,
    EDiscoveryType_Mineral = 5,
    EDiscoveryType_Sector = 6,
    EDiscoveryType_Building = 7,
    EDiscoveryType_Interactable = 8,
    EDiscoveryType_Sentinel = 9,
    EDiscoveryType_Starship = 10,
    EDiscoveryType_Artifact = 11,
    EDiscoveryType_Mystery = 12,
    EDiscoveryType_Treasure = 13,
    EDiscoveryType_Control = 14,
    EDiscoveryType_HarvestPlant = 15,
    EDiscoveryType_FriendlyDrone = 16,
}

class cGcDiscoveryType
{
    static unsigned long long muNameHash = 0x5BB97397B6B70C3A;
    static unsigned long long muTemplateHash = 0x9066D5BF2A5AAA32;

    eDiscoveryType DiscoveryType;
}
