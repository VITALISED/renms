#pragma once
#include <metadata/metadata_common.h>

class cGcMissionConditionHasTechnology
{
    static unsigned long long muNameHash = 0x7454AD5214251C68;
    static unsigned long long muTemplateHash = 0x8E444B511B45E75D;

    TkID<128> mTechnology;
    bool mbAllowPartiallyInstalled;
    bool mbTeachIfNotKnown;
    bool mbTakeTechFromSeasonData;
}
