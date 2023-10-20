#pragma once
#include <metadata/metadata_common.h>

class cGcMissionIDEpochPair
{
    static unsigned long long muNameHash = 0x79FB303D79E7B435;
    static unsigned long long muTemplateHash = 0x48959E8D8B7150F7;

    TkID<128> mMissionID;
    unsigned long long mui64RecurrenceDeadline;
}
