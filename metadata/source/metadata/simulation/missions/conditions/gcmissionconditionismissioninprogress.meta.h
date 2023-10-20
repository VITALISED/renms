#pragma once
#include <metadata/metadata_common.h>

class cGcMissionConditionIsMissionInProgress
{
    static unsigned long long muNameHash = 0x8FA593E74FC53DD5;
    static unsigned long long muTemplateHash = 0x2890453EA87F62D7;

    TkID<128> mMissionID;
    bool mbMustBeSelectedMission;
}
