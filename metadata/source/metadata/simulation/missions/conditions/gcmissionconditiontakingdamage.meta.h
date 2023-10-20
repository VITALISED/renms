#pragma once
#include <metadata/metadata_common.h>

class cGcMissionConditionTakingDamage
{
    static unsigned long long muNameHash = 0x1C7BDD4B8265FAA3;
    static unsigned long long muTemplateHash = 0x3F266D6E329972D6;

    bool mbRequireShieldDown;
    TkID<128> mDamageID;
}
