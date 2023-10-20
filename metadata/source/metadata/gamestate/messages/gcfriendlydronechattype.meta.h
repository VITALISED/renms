#pragma once
#include <metadata/metadata_common.h>
enum eFriendlyDroneChatType
{
    EFriendlyDroneChatType_Summoned = 0,
    EFriendlyDroneChatType_Unsummoned = 1,
    EFriendlyDroneChatType_BecomeWanted = 2,
    EFriendlyDroneChatType_LoseWanted = 3,
    EFriendlyDroneChatType_Idle = 4,
}

class cGcFriendlyDroneChatType
{
    static unsigned long long muNameHash = 0x6E9F63DB3D3055;
    static unsigned long long muTemplateHash = 0x616AD1CA5E74AA15;

    eFriendlyDroneChatType FriendlyDroneChatType;
}
