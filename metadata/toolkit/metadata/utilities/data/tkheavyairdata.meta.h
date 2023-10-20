#pragma once
#include <metadata/metadata_common.h>
enum eEmitterShape
{
    EEmitterShape_Sphere = 0,
    EEmitterShape_UpperHalfSphere = 1,
    EEmitterShape_BottomHalfSphere = 2,
}

class cTkHeavyAirData
{
    static unsigned long long muNameHash = 0xCB25F378CA730AFC;
    static unsigned long long muTemplateHash = 0x5ED48C0489FB7DD4;

    cTkFixedString<128,char> macMaterial;
    int miNumberOfParticles;
    float mfRadius;
    float mfRadiusY;
    float mfMinParticleLifetime;
    float mfMaxParticleLifetime;
    float mfFadeTime;
    float mfSpeedFadeInTime;
    float mfMinVisibleSpeed;
    float mfSpeedFadeOutTime;
    float mfMaxVisibleSpeed;
    float mfSoftFadeStrength;
    float mfSpawnRotationRange;
    cTkVector3 mMajorDirection;
    cTkVector3 mScaleRange;
    cTkVector3 mRotationSpeedRange;
    cTkVector3 mTwinkleRange;
    cTkVector3 mAmplitudeMin;
    cTkVector3 mAmplitudeMax;
    cTkColour mColour1;
    cTkColour mColour2;
    eEmitterShape EmitterShape;
}
