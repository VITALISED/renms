#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcStormProperties
{
    static unsigned long long muNameHash = 0x82B1B19A1A57F975;
    static unsigned long long muTemplateHash = 0xA85160500E3060F0;

    float mfWeighting;
    cGcFogProperties Fog;
    cGcWeatherColourModifiers ColourModifiers;
    cTkFixedArray<cTkVector2> maHazardModifiers;
}
