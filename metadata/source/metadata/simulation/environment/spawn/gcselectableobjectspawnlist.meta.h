#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/environment/spawn/gcselectableobjectspawndata.meta.h>

class cGcSelectableObjectSpawnList
{
    static unsigned long long muNameHash = 0xA8FBF05C737FA4E2;
    static unsigned long long muTemplateHash = 0xDDCC50E4A9E9724D;

    TkID<128> mName;
    cTkDynamicArray<cGcSelectableObjectSpawnData> maObjects;
}
