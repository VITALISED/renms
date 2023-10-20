#pragma once
#include <metadata/metadata_common.h>

class cGcAreaDamageData
{
    static unsigned long long muNameHash = 0x38D56749327FCFE6;
    static unsigned long long muTemplateHash = 0xDA0025A12F5C626D;

    TkID<128> mId;
    float mfRadius;
    float mfDelayPerMetre;
    TkID<128> mPlayerDamageId;
    float mfDamage;
    bool mbInstantKill;
    bool mbDamagePlayers;
    bool mbDamageCreatures;
}
