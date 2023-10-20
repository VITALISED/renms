#pragma once
#include <metadata/metadata_common.h>

class cGcSolarSystemEventWarpOut
{
    static unsigned long long muNameHash = 0xC217A4AF3130299A;
    static unsigned long long muTemplateHash = 0xFB4A23D1D214B86E;

    float mfTime;
    cTkFixedString<32,char> macSquadName;
    cTkVector2 mWarpIntervalRange;
}
