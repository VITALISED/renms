#pragma once
#include <metadata/metadata_common.h>

class cGcCreatureBaitComponentData
{
    static unsigned long long muNameHash = 0x398860441F320FF2;
    static unsigned long long muTemplateHash = 0x98F3859A288FF087;

    cTkDynamicArray<TkID<128>> maAttractList;
    float mfBaitStrength;
    float mfBaitRadius;
    bool mbDebug;
    bool mbInducesRage;
}
