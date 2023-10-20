#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcFogProperties
{
    static unsigned long long muNameHash = 0x32F1C073DAE21750;
    static unsigned long long muTemplateHash = 0x35844421A6C552B4;

    float mfFogStrength;
    float mfFogMax;
    float mfFogColourStrength;
    float mfFogColourMax;
    float mfHeightFogStrength;
    float mfHeightFogFadeOutStrength;
    float mfHeightFogOffset;
    float mfHeightFogMax;
    float mfFogHeight;
    cGcHeavyAirSetting HeavyAir;
    float mfCloudRatio;
    float mfFullscreenEffect;
    float mfDepthOfField;
    float mfDepthOfFieldDistance;
    float mfDepthOfFieldFade;
    bool mbIsRaining;
    float mfRainWetness;
}
