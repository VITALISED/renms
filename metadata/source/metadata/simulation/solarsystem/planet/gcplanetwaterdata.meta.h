#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcPlanetWaterData
{
    static unsigned long long muNameHash = 0x98F83A1A50531877;
    static unsigned long long muTemplateHash = 0xF87D71ED70DA7A24;

    int miColourIndex;
    float mfWaterStrength;
    float mfWaterColourStrength;
    float mfWaterMultiplyStrength;
    float mfWaterMultiplyMax;
    float mfWaterRoughness;
    float mfFresnelPower;
    float mfFresnelMin;
    float mfFresnelMax;
    float mfWave1Scale;
    float mfWave1Height;
    float mfWave1Speed;
    float mfWave2Scale;
    float mfWave2Height;
    float mfWave2Speed;
    float mfNormalMap1Scale;
    float mfNormalMap1Speed;
    float mfNormalMap2Scale;
    float mfNormalMap2Speed;
    float mfFoamFadeHeight;
    float mfFoam1Scale;
    float mfFoam1Speed;
    float mfFoam2Scale;
    float mfFoam2Speed;
    cGcPlanetHeavyAirData HeavyAir;
}
