#pragma once
#include <metadata/metadata_common.h>
enum ePlanetSize
{
    EPlanetSize_Large = 0,
    EPlanetSize_Medium = 1,
    EPlanetSize_Small = 2,
    EPlanetSize_Moon = 3,
}

class cGcPlanetSize
{
    static unsigned long long muNameHash = 0xE198F55796BC6E2F;
    static unsigned long long muTemplateHash = 0xF0DADAF6E563CFD9;

    ePlanetSize PlanetSize;
}
