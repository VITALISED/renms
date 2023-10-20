#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/gccreaturespawndata.meta.h>
#include <metadata/simulation/environment/gcobjectspawndata.meta.h>
#include <metadata/simulation/environment/spawn/gcselectableobjectspawnlist.meta.h>

class cGcEnvironmentSpawnData
{
    static unsigned long long muNameHash = 0x1B03CB87DECA6BCC;
    static unsigned long long muTemplateHash = 0xA77C761194465BA6;

    cTkDynamicArray<cGcCreatureSpawnData> maCreatures;
    cTkDynamicArray<cGcObjectSpawnData> maDistantObjects;
    cTkDynamicArray<cGcObjectSpawnData> maLandmarks;
    cTkDynamicArray<cGcObjectSpawnData> maObjects;
    cTkDynamicArray<cGcObjectSpawnData> maDetailObjects;
    cTkDynamicArray<cGcSelectableObjectSpawnList> maSelectableObjects;
}
