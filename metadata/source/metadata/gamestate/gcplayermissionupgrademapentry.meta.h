#pragma once
#include <metadata/metadata_common.h>

class cGcPlayerMissionUpgradeMapEntry
{
    static unsigned long long muNameHash = 0x783F7F56522EAFC6;
    static unsigned long long muTemplateHash = 0x18837F6683177204;

    TkID<128> mMission;
    int miMinProgress;
    int miCompletePoint;
    TkID<128> mNewMission;
    cTkDynamicArray<TkID<128>> maCompletedMissions;
}
