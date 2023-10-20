#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcWeatherColourModifiers
{
    static unsigned long long muNameHash = 0x63BA6E198CA6237E;
    static unsigned long long muTemplateHash = 0xD425864C90EB0317;

    cGcColourModifier SkyColour;
    cGcColourModifier SkyUpperColour;
    cGcColourModifier HorizonColour;
    cGcColourModifier SunColour;
    cGcColourModifier FogColour;
    cGcColourModifier HeightFogColour;
    cGcColourModifier LightColour;
    cGcColourModifier CloudColour1;
    cGcColourModifier CloudColour2;
    cTkFixedArray<cGcColourModifier> maHeavyAirColour;
}
