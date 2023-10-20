#pragma once
#include <metadata/metadata_common.h>
enum eInteractionBufferType
{
    EInteractionBufferType_Distress_Signal = 0,
    EInteractionBufferType_Crate = 1,
    EInteractionBufferType_Destructable = 2,
    EInteractionBufferType_Terrain = 3,
    EInteractionBufferType_Cost = 4,
    EInteractionBufferType_Building = 5,
    EInteractionBufferType_Creature = 6,
    EInteractionBufferType_Maintenance = 7,
    EInteractionBufferType_Personal = 8,
    EInteractionBufferType_Personal_Maintenance = 9,
    EInteractionBufferType_FireteamSync = 10,
}

class cGcInteractionBufferType
{
    static unsigned long long muNameHash = 0x56096224708D16B;
    static unsigned long long muTemplateHash = 0xA7327182011FA2C6;

    eInteractionBufferType InteractionBufferType;
}
