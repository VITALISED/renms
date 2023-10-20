#pragma once
#include <metadata/metadata_common.h>

class cGcStoryEntryBranch
{
    static unsigned long long muNameHash = 0x259D492A614EC840;
    static unsigned long long muTemplateHash = 0xAF677C1767AD4C6C;

    TkID<256> mEntry;
    TkID<128> mRequiresMission;
    bool mbConditionMissionComplete;
}
