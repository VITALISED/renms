#pragma once
#include <metadata/metadata_common.h>

class cGcCameraShakeMechanicalData
{
    static unsigned long long muNameHash = 0x40BF52C4D8757B1A;
    static unsigned long long muTemplateHash = 0xDDC3F5342C985F9F;

    bool mbActive;
    cTkVector3 mShakeStrength;
    cTkVector3 mShakeFrequency;
    cTkVector3 mExtraShakeFrequency;
    cTkVector3 mVibrateStrength;
    cTkVector3 mVibrateFrequency;
    cTkVector3 mExtraVibrateFrequency;
}
