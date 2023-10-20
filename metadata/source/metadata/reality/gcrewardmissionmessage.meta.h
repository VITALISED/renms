#pragma once
#include <metadata/metadata_common.h>

class cGcRewardMissionMessage
{
    static unsigned long long muNameHash = 0x7A4371C33E264E2C;
    static unsigned long long muTemplateHash = 0x17C77D54ACACD0A5;

    TkID<128> mMessageID;
    bool mbBroadcastInMultiplayer;
}
