#pragma once
#include <metadata/metadata_common.h>
enum eNPCInteractiveObjectType
{
    ENPCInteractiveObjectType_Idle = 0,
    ENPCInteractiveObjectType_Generic = 1,
    ENPCInteractiveObjectType_Chair = 2,
    ENPCInteractiveObjectType_Conversation = 3,
    ENPCInteractiveObjectType_WatchShip = 4,
    ENPCInteractiveObjectType_Shop = 5,
    ENPCInteractiveObjectType_Dance = 6,
    ENPCInteractiveObjectType_None = 7,
}

class cGcNPCInteractiveObjectType
{
    static unsigned long long muNameHash = 0x6C6EDC3D5C0DA932;
    static unsigned long long muTemplateHash = 0x57DED3CFF0EFEFEB;

    eNPCInteractiveObjectType NPCInteractiveObjectType;
}
