#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gameplay/gcsentinelspawndata.meta.h>

class cGcSentinelSpawnWave
{
    static unsigned long long muNameHash = 0x5CF9A5D0C4877494;
    static unsigned long long muTemplateHash = 0x128DFED6F90E6776;

    TkID<128> mId;
    cTkDynamicArray<cGcSentinelSpawnData> maSpawns;
    int miReinforceAt;
}
