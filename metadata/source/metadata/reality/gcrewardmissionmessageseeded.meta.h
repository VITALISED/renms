#pragma once
#include <metadata/metadata_common.h>

class cGcRewardMissionMessageSeeded
{
    static unsigned long long muNameHash = 0x56DEE85C9E579653;
    static unsigned long long muTemplateHash = 0x5FA26355282BB41A;

    TkID<128> mMessageID;
    bool mbBroadcastInMultiplayer;
    bool mbBroadcastToActiveMultiplayerMission;
    TkID<128> mSpecificMissionID;
}
