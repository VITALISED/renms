#pragma once
#include <metadata/metadata_common.h>
enum eTeleportRewardType
{
    ETeleportRewardType_None = 0,
    ETeleportRewardType_ToBase = 1,
    ETeleportRewardType_Station0 = 2,
    ETeleportRewardType_Station1 = 3,
    ETeleportRewardType_Station2 = 4,
    ETeleportRewardType_Station3 = 5,
    ETeleportRewardType_Atlas = 6,
}

class cGcRewardTeleport
{
    static unsigned long long muNameHash = 0x9204A5F1450F4D7;
    static unsigned long long muTemplateHash = 0x9F2BA459DCEC25BC;

    eTeleportRewardType TeleportRewardType;
}
