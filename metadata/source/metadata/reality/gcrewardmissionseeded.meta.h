#pragma once
#include <metadata/metadata_common.h>

class cGcRewardMissionSeeded
{
    static unsigned long long muNameHash = 0x71B9EA7C3B789C6B;
    static unsigned long long muTemplateHash = 0xD6527A0E3C6EE892;

    TkID<128> mMission;
    TkID<128> mMissionNoGroundCombat;
    TkID<128> mMissionNoSpaceCombat;
    bool mbInheritActiveMultiplayerMissionSeed;
}
