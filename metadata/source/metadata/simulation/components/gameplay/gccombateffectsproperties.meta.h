#pragma once
#include <metadata/metadata_common.h>

class cGcCombatEffectsProperties
{
    static unsigned long long muNameHash = 0xC39E8583E846A389;
    static unsigned long long muTemplateHash = 0x4B375D7FDF923AFD;

    bool mbIsAffected;
    bool mbIgnoreFromOtherPlayers;
    bool mbIgnoreFromSelf;
    float mfDurationMultiplier;
    float mfDamageMultiplier;
}
