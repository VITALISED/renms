#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcBackgroundSpaceEncounterInfo
{
    static unsigned long long muNameHash = 0x9803054FC61F20F4;
    static unsigned long long muTemplateHash = 0x4D053C039EED67A0;

    TkID<128> mId;
    cGcBackgroundSpaceEncounterSpawnConditions SpawnConditions;
    float mfSelectionWeighting;
    float mfSpawnChance;
    float mfSpawnDistance;
    float mfMinDuration;
    float mfDespawnDistance;
    cGcPulseEncounterSpawnObject Encounter;
}
