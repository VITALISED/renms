#pragma once
#include <metadata/metadata_common.h>

class cGcPlanetWaterColourData
{
    static unsigned long long muNameHash = 0x5148874790D0404C;
    static unsigned long long muTemplateHash = 0xFE16295F97CAA527;

    cTkColour mWaterFogColourNear;
    cTkColour mWaterFogColourFar;
    cTkColour mWaterColourBase;
    cTkColour mWaterColourAdd;
    cTkColour mFoamColour;
}
