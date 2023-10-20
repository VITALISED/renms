#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gameplay/gcplayerexperienceasteroidcreaturespawndata.meta.h>

class cGcPlayerExperienceAsteroidCreatureSpawnTable
{
    static unsigned long long muNameHash = 0xC49FE6E5B9227EF6;
    static unsigned long long muTemplateHash = 0x13686FB01961A6D;

    float mfSmallAsteroidSpawnPercent;
    cTkDynamicArray<cGcPlayerExperienceAsteroidCreatureSpawnData> maSmallAsteroidSpawns;
    float mfMediumAsteroidSpawnPercent;
    cTkDynamicArray<cGcPlayerExperienceAsteroidCreatureSpawnData> maMediumAsteroidSpawns;
    float mfLargeAsteroidSpawnPercent;
    cTkDynamicArray<cGcPlayerExperienceAsteroidCreatureSpawnData> maLargeAsteroidSpawns;
}
