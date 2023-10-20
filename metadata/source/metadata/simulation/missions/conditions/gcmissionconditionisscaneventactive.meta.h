#pragma once
#include <metadata/metadata_common.h>

class cGcMissionConditionIsScanEventActive
{
    static unsigned long long muNameHash = 0xDF80EC28C687305E;
    static unsigned long long muTemplateHash = 0xF3CBA8732CB15BD5;

    TkID<256> mEvent;
    bool mbMustMatchThisMissionSeed;
}
