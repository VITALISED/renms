#pragma once
#include <metadata/metadata_common.h>

class cGcJourneyMilestoneData
{
    static unsigned long long muNameHash = 0xC35BDABF76750407;
    static unsigned long long muTemplateHash = 0xE8BF2A6A86ADC900;

    TkID<128> mJourneyMilestoneId;
    int miPointsToUnlock;
    TkID<256> mJourneyMilestoneTitle;
    TkID<256> mJourneyMilestoneTitleLower;
}
