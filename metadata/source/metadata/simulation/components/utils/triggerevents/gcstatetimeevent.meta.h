#pragma once
#include <metadata/metadata_common.h>

class cGcStateTimeEvent
{
    static unsigned long long muNameHash = 0x29C73977774C3241;
    static unsigned long long muTemplateHash = 0x2D93A002C61202AA;

    float mfSeconds;
    float mfRandomSeconds;
    bool mbUseMissionClock;
}
