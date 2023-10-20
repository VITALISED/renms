#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/missions/scheduling/gcdate.meta.h>

class cGcMissionSchedulingData
{
    static unsigned long long muNameHash = 0xC7D1E140B3A1C6B2;
    static unsigned long long muTemplateHash = 0x28AEB8E606F98613;

    cTkClassPointer mRecurrenceType;
    cGcDate StartDate;
    cGcDate EndDate;
    bool mbIndependentStart;
    bool mbHasEndDate;
    unsigned long long mui64EarlyEndOffset;
    cTkDynamicArray<TkID<128>> maMissionIDs;
}
