#pragma once
#include <metadata/metadata_common.h>
enum eCentreJourneyDestination
{
    ECentreJourneyDestination_Next = 0,
    ECentreJourneyDestination_Abandoned = 1,
    ECentreJourneyDestination_Vicious = 2,
    ECentreJourneyDestination_Lush = 3,
    ECentreJourneyDestination_Balanced = 4,
}

class cGcRewardJourneyThroughCentre
{
    static unsigned long long muNameHash = 0x1D30BD6C3E0FC228;
    static unsigned long long muTemplateHash = 0xC6CE7618FE079C1D;

    eCentreJourneyDestination CentreJourneyDestination;
}
