#pragma once
#include <metadata/metadata_common.h>

class cGcPlanetWeatherColourData
{
    static unsigned long long muNameHash = 0xA699A80ACABBB3C5;
    static unsigned long long muTemplateHash = 0x79EC01ECC601AA7F;

    cTkColour mSkyColour;
    cTkColour mSkyUpperColour;
    cTkColour mSkySolarColour;
    cTkColour mHorizonColour;
    cTkColour mSunColour;
    cTkColour mFogColour;
    cTkColour mHeightFogColour;
    cTkVector3 mSkyGradientSpeed;
    cTkColour mLightColour;
    cTkColour mCloudColour1;
    cTkColour mCloudColour2;
}
