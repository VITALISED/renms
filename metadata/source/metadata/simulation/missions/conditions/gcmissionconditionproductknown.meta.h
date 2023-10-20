#pragma once
#include <metadata/metadata_common.h>

class cGcMissionConditionProductKnown
{
    static unsigned long long muNameHash = 0x7C5208D16FF2D5BF;
    static unsigned long long muTemplateHash = 0x893F9280E32D11D2;

    TkID<128> mProduct;
    bool mbDependentOnSeasonMilestone;
    bool mbTakeProductFromSeasonData;
}
