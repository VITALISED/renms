#pragma once
#include <metadata/metadata_common.h>

class cGcMissionConditionMissionCompleted
{
    static unsigned long long muNameHash = 0xC28C1E8A4FA47E3B;
    static unsigned long long muTemplateHash = 0x8C2BF8C5C2322B2;

    TkID<128> mMissionID;
    bool mbTakeIDFromSeasonData;
    bool mbCalculateTextMissionTargetFromStageIndex;
}
