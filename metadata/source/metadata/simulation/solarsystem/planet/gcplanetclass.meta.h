#pragma once
#include <metadata/metadata_common.h>
enum ePlanetClass
{
    EPlanetClass_Default = 0,
    EPlanetClass_Initial = 1,
    EPlanetClass_InInitialSystem = 2,
}

class cGcPlanetClass
{
    static unsigned long long muNameHash = 0x9EB26F87ECDE68DC;
    static unsigned long long muTemplateHash = 0x69BD755CF9F65D66;

    ePlanetClass PlanetClass;
}
