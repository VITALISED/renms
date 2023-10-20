#pragma once
#include <metadata/metadata_common.h>
enum eGlobalMission
{
    EGlobalMission_Atlas = 0,
    EGlobalMission_BlackHole = 1,
    EGlobalMission_Anomaly = 2,
    EGlobalMission_Explore = 3,
}

class cGcRewardChangeGlobalMission
{
    static unsigned long long muNameHash = 0xAD03B051106BCE0A;
    static unsigned long long muTemplateHash = 0x3B3EF978A93CD288;

    eGlobalMission GlobalMission;
}
