#pragma once
#include <metadata/metadata_common.h>

class cGcCameraShakeAction
{
    static unsigned long long muNameHash = 0x8C20E93C658FEFB1;
    static unsigned long long muTemplateHash = 0x1E28DC14407484A8;

    TkID<128> mShake;
    float mfFalloffMin;
    float mfFalloffMax;
}
