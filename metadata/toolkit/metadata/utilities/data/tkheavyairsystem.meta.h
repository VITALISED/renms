#pragma once
#include <metadata/metadata_common.h>

class cTkHeavyAirSystem
{
    static unsigned long long muNameHash = 0x9564BC3EDB74BBA1;
    static unsigned long long muTemplateHash = 0x2BAB61256BF5B670;

    cTkFixedString<128,char> macMaterial;
    cTkVector3 mMajorDirection;
    cTkVector3 mScaleRange;
    cTkVector3 mRotationSpeedRange;
    cTkVector3 mFadeSpeedRange;
    cTkVector3 mTwinkleRange;
    cTkVector3 mAmplitudeMin;
    cTkVector3 mAmplitudeMax;
    cTkColour mColour1;
    float mfColour1Alpha;
    cTkColour mColour2;
    float mfColour2Alpha;
}
