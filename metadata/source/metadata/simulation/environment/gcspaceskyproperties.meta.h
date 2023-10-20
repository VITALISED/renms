#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/solarsystem/planet/gcplanetweathercolourindex.meta.h>

class cGcSpaceSkyProperties
{
    static unsigned long long muNameHash = 0xCB4FC853C028D8AE;
    static unsigned long long muTemplateHash = 0x157FDABAEA56DDB6;

    cGcPlanetWeatherColourIndex ColourIndex;
    cTkColour mPlanetSkyColour;
    cTkColour mPlanetHorizonColour;
    float mfSunStrength;
    float mfSunSize;
    float mfStarVisibility;
    float mfCenterPower;
    float mfAtmosphereThickness;
    float mfHorizonMultiplier;
    float mfHorizonFadeSpeed;
    float mfPlanetFogStrength;
    float mfSpaceFogStrength;
    float mfSpaceFogColourStrength;
    float mfSpaceFogColour2Strength;
    float mfSpaceFogMax;
    float mfSpaceFogPlanetMax;
    float mfNebulaFrequency;
    float mfNebulaSparseness;
    float mfNebulaWispyness;
    float mfNebulaWispyness1;
    float mfNebulaBrightness;
    float mfNebulaSeed;
    float mfNebulaTendrilStrength;
    float mfNebulaFogAmount;
    float mfNebulaCloudStrength;
    float mfNebulaCloudStrength1;
    float mfNebulaNoiseFrequency;
    float mfCloudNoiseFrequency;
    float mfNebulaTurbulenceStrength;
    float mfNebulaFBMStrength;
    float mfNebulaFBMStrength1;
    float mfNebulaDistortionStrength;
}
