#pragma once
#include <metadata/metadata_common.h>
enum eMilestone
{
    EMilestone_Bronze = 0,
    EMilestone_Silver = 1,
    EMilestone_Gold = 2,
}

class cGcMissionSequenceWaitForStatMilestone
{
    static unsigned long long muNameHash = 0xCD771E985A27F526;
    static unsigned long long muTemplateHash = 0xC0D46638AF53103D;

    cTkFixedString<128,char> macMessage;
    TkID<128> mStat;
    eMilestone Milestone;
    bool mbEveryMilestone;
    cTkFixedString<128,char> macDebugText;
}
