#pragma once
#include <metadata/metadata_common.h>
enum eTestEncounterType
{
    ETestEncounterType_AnyEncounter = 0,
    ETestEncounterType_AnyObject = 1,
    ETestEncounterType_SpecificObject = 2,
    ETestEncounterType_Trader = 3,
    ETestEncounterType_AbandonedFreighter = 4,
    ETestEncounterType_AnyEncounterOtherThanTheNamedOne = 5,
}

class cGcMissionConditionPulseEncounterActive
{
    static unsigned long long muNameHash = 0x56207A2C2009340;
    static unsigned long long muTemplateHash = 0xAB5AE414E5866353;

    eTestEncounterType TestEncounterType;
    TkID<128> mSpecificObjectID;
    bool mbRequireFullySpawned;
}
