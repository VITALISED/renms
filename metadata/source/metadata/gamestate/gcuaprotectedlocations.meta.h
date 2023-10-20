#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/gcprotectedlocation.meta.h>

class cGcUAProtectedLocations
{
    static unsigned long long muNameHash = 0xD522308022E072F4;
    static unsigned long long muTemplateHash = 0xD0E3C76254330565;

    unsigned long long mui64UA;
    cTkDynamicArray<cGcProtectedLocation> maProtectedLocations;
}
