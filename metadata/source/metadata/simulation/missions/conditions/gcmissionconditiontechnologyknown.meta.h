#pragma once
#include <metadata/metadata_common.h>

class cGcMissionConditionTechnologyKnown
{
    static unsigned long long muNameHash = 0x1E4A17D964305DC4;
    static unsigned long long muTemplateHash = 0xFC7E542334A352B9;

    TkID<128> mTechnology;
    bool mbDependentOnSeasonMilestone;
    bool mbTakeTechFromSeasonData;
}
