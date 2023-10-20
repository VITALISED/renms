#pragma once
#include <metadata/metadata_common.h>

class cGcMissionConditionIsTechnologyRepaired
{
    static unsigned long long muNameHash = 0x24D022A0BCD713A0;
    static unsigned long long muTemplateHash = 0xCE976A8B51A128BF;

    TkID<128> mTechnology;
    int miRepairedComponents;
    TkID<128> mSpecificComponent;
}
