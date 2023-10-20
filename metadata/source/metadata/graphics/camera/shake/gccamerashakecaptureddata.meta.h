#pragma once
#include <metadata/metadata_common.h>

class cGcCameraShakeCapturedData
{
    static unsigned long long muNameHash = 0x472B5C1A8B3B1505;
    static unsigned long long muTemplateHash = 0xFF9232FF9E402945;

    bool mbActive;
    float mfShakeStrength;
    float mfShakeFrequency;
    float mfVibrateStrength;
    float mfVibrateFrequency;
}
