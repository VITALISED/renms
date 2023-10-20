#pragma once
#include <metadata/metadata_common.h>
enum eNPCProp
{
    ENPCProp_None = 0,
    ENPCProp_IPad = 1,
    ENPCProp_HoloBlob = 2,
    ENPCProp_HoloFrigate = 3,
    ENPCProp_HoloShip = 4,
    ENPCProp_HoloMultitool = 5,
    ENPCProp_HoloSolarSystem = 6,
    ENPCProp_Container = 7,
    ENPCProp_Box = 8,
    ENPCProp_Cup = 9,
    ENPCProp_DontCare = 10,
    ENPCProp_RandomHologram = 11,
    ENPCProp_HoloDrone = 12,
}

class cGcNPCPropType
{
    static unsigned long long muNameHash = 0x69F60839059BF3CD;
    static unsigned long long muTemplateHash = 0x6A5117479225A1A;

    eNPCProp NPCProp;
}
