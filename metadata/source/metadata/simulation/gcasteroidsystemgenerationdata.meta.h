#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/gcasteroidgenerationdata.meta.h>

class cGcAsteroidSystemGenerationData
{
    static unsigned long long muNameHash = 0x6D874860E2F7237A;
    static unsigned long long muTemplateHash = 0x58D85EFD3CD1B909;

    cGcAsteroidGenerationData CommonAsteroidData;
    cGcAsteroidGenerationData RingAsteroidData;
    cGcAsteroidGenerationData LargeAsteroidData;
    cGcAsteroidGenerationData RareAsteroidData;
}
