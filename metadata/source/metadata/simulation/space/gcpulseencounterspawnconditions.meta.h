#pragma once
#include <metadata/metadata_common.h>

class cGcPulseEncounterSpawnConditions
{
    static unsigned long long muNameHash = 0x662E605B574D59AB;
    static unsigned long long muTemplateHash = 0xB32222FDB5279407;

    bool mbAllowedInCreative;
    bool mbAllowedInEmptySystem;
    bool mbAllowedDuringTutorial;
    bool mbAllowedBeyondPortals;
    bool mbAllowedWhileOnMPMission;
    TkID<128> mRequiresProduct;
    TkID<128> mRequiresMissionComplete;
    TkID<128> mRequiresMissionActive;
    TkID<128> mRequiresMissionNotComplete;
    TkID<128> mRequiresMissionNotActive;
    bool mbRequiresAlienShip;
    bool mbStandardEncounter;
    bool mbMissionEncounter;
}
