#pragma once
#include <metadata/metadata_common.h>

class cGcEnvironmentProperties
{
    static unsigned long long muNameHash = 0xB125AED843BB9164;
    static unsigned long long muTemplateHash = 0x5878DB43951227CC;

    float mfFlightFogHeight;
    float mfFlightFogBlend;
    float mfCloudHeightMin;
    float mfCloudHeightMax;
    float mfHeavyAirHeightMin;
    float mfHeavyAirHeightMax;
    float mfPlanetObjectSwitch;
    float mfPlanetLodSwitch0;
    float mfPlanetLodSwitch0Elevation;
    float mfPlanetLodSwitch1;
    float mfPlanetLodSwitch2;
    float mfPlanetLodSwitch3;
    float mfAsteroidFadeHeightMin;
    float mfAsteroidFadeHeightMax;
    cTkFixedArray<float> maSkyHeight;
    float mfSkyAtmosphereHeight;
    float mfHorizonBlendHeight;
    float mfHorizonBlendLength;
    float mfSkyColourHeight;
    float mfSkyColourBlendLength;
    float mfSkyPositionHeight;
    float mfSkyPositionBlendLength;
    float mfSolarSystemLUTHeight;
    float mfSolarSystemLUTBlendLength;
    float mfAtmosphereStartHeight;
    float mfAtmosphereEndHeight;
    float mfStratosphereHeight;
}
