#pragma once
#include <metadata/metadata_common.h>

class cGcDistanceScaleComponentData
{
    static unsigned long long muNameHash = 0xB150A87B0DD42807;
    static unsigned long long muTemplateHash = 0xEE335C704F87FFA8;

    bool mbUseGlobals;
    float mfScale;
    float mfMinDistance;
    float mfMaxDistance;
    float mfMinHeight;
    float mfMaxHeight;
    bool mbDisabledWhenOnFreighter;
}
