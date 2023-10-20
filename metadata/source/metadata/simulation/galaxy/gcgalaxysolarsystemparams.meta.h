#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/galaxy/gcgalaxysolarsystemorbitparams.meta.h>

class cGcGalaxySolarSystemParams
{
    static unsigned long long muNameHash = 0x3454C9AB7AAC46D9;
    static unsigned long long muTemplateHash = 0x46D508F9992D3331;

    cGcGalaxySolarSystemOrbitParams PlanetParameters;
    cGcGalaxySolarSystemOrbitParams MoonParameters;
    cTkFixedArray<float> maPlanetRadii;
    float mfSystemTilt;
    float mfDefaultDistance;
    float mfVisitedPlanetAlpha;
    float mfNonVisitedPlanetAlpha;
}
