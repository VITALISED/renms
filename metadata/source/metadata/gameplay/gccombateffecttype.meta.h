#pragma once
#include <metadata/metadata_common.h>
enum eCombatEffectType
{
    ECombatEffectType_None = 0,
    ECombatEffectType_Fire = 1,
    ECombatEffectType_Stun = 2,
    ECombatEffectType_Slow = 3,
}

class cGcCombatEffectType
{
    static unsigned long long muNameHash = 0xCC36FE8AD202DF8;
    static unsigned long long muTemplateHash = 0xF353736FC3B7065;

    eCombatEffectType CombatEffectType;
}
