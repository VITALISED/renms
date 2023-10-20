#pragma once
#include <metadata/metadata_common.h>

class cGcRewardMission
{
    static unsigned long long muNameHash = 0xFCFEF60947A44802;
    static unsigned long long muTemplateHash = 0x41AB2A7A20D73AC2;

    TkID<128> mMission;
    bool mbSetAsSelected;
    bool mbFailRewardIfMissionActive;
}
