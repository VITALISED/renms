#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcalienrace.meta.h>
#include <metadata/simulation/environment/spawn/gcselectableobjectdata.meta.h>

class cGcSelectableObjectList
{
    static unsigned long long muNameHash = 0x5035CC19B55D3442;
    static unsigned long long muTemplateHash = 0x933E6844872C884;

    TkID<128> mName;
    cGcAlienRace Race;
    cTkDynamicArray<cGcSelectableObjectData> maOptions;
}
