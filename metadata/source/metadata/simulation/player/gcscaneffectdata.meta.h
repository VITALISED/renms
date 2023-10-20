#pragma once
#include <metadata/metadata_common.h>
enum eScanEffectType
{
    EScanEffectType_Building = 0,
    EScanEffectType_TargetShip = 1,
    EScanEffectType_Creature = 2,
    EScanEffectType_Ground = 3,
    EScanEffectType_Objects = 4,
}

class cGcScanEffectData
{
    static unsigned long long muNameHash = 0xCB9E3018E759F166;
    static unsigned long long muTemplateHash = 0x1D30CF3BCBA8A73D;

    TkID<128> mId;
    eScanEffectType ScanEffectType;
    cTkColour mColour;
    float mfBasecolourIntensity;
    float mfScanlinesSeparation;
    float mfFresnelIntensity;
    float mfGlowIntensity;
    float mfWaveOffset;
    bool mbWaveActive;
    bool mbFixedUpAxis;
    bool mbTransparent;
    bool mbModelFade;
    float mfFadeInTime;
    float mfFadeOutTime;
}
