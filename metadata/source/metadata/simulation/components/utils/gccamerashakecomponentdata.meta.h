#pragma once
#include <metadata/metadata_common.h>

class cGcCameraShakeComponentData
{
    static unsigned long long muNameHash = 0x77B3408A8150441E;
    static unsigned long long muTemplateHash = 0x35996503195FB978;

    TkID<128> mShakeID;
    float mfFalloffDistanceMin;
    float mfFalloffDistanceMax;
}
