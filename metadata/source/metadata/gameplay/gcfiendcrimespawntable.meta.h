#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gameplay/gcfiendcrime.meta.h>
#include <metadata/gameplay/gcfiendcrimespawndata.meta.h>

class cGcFiendCrimeSpawnTable
{
    static unsigned long long muNameHash = 0x4EBB7BDC5EE300EA;
    static unsigned long long muTemplateHash = 0xF11ACFCECBC95ACF;

    cGcFiendCrime Crime;
    float mfResponseRate;
    cTkDynamicArray<cGcFiendCrimeSpawnData> maSpawns;
}
