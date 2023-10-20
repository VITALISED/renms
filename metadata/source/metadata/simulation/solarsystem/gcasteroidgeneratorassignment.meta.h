#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/solarsystem/gcsolarsystemlocatorchoice.meta.h>

class cGcAsteroidGeneratorAssignment
{
    static unsigned long long muNameHash = 0xA3D40DA508711D13;
    static unsigned long long muTemplateHash = 0xD35227A699C8923E;

    int miPlanetIndex;
    cGcSolarSystemLocatorChoice Locator;
    cTkSeed mSeed;
    int miAsteroidCount;
}
