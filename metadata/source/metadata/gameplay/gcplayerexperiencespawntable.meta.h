#pragma once
#include <metadata/metadata_common.h>
enum eExperienceSpawnType
{
    EExperienceSpawnType_Freighter = 0,
    EExperienceSpawnType_Mission = 1,
}
#include <?>

class cGcPlayerExperienceSpawnTable
{
    static unsigned long long muNameHash = 0xA1B202DE9A10A705;
    static unsigned long long muTemplateHash = 0xE2D862A8402D7F11;

    TkID<128> mEvent;
    eExperienceSpawnType ExperienceSpawnType;
    float mfResponseRate;
    float mfPerSpawnDelay;
    bool mbDestroy;
    cTkDynamicArray<cGcPlayerExperienceSpawnData> maSpawns;
}
