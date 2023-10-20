#pragma once
#include <metadata/metadata_common.h>

class cGcSolarSystemTraderSpawnData
{
    static unsigned long long muNameHash = 0x436337B25B8F877E;
    static unsigned long long muTemplateHash = 0x4A9EA671BB4E86D8;

    int miMaxToSpawn;
    float mfInitialTakeoffDelay;
    cTkVector2 mSequenceTakeoffDelay;
    int miChanceToDelayLaunch;
}
