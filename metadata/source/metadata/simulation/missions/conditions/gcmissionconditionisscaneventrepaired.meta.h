#pragma once
#include <metadata/metadata_common.h>

class cGcMissionConditionIsScanEventRepaired
{
    static unsigned long long muNameHash = 0xA601980170B475C0;
    static unsigned long long muTemplateHash = 0xA4633034F695960A;

    TkID<256> mEvent;
    bool mbCheckForAllRepairsInBuilding;
}
