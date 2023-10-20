#pragma once
#include <metadata/metadata_common.h>
enum eDeathConsequencesDifficulty
{
    EDeathConsequencesDifficulty_None = 0,
    EDeathConsequencesDifficulty_ItemGrave = 1,
    EDeathConsequencesDifficulty_DestroyItems = 2,
    EDeathConsequencesDifficulty_DestroySave = 3,
}

class cGcDeathConsequencesDifficultyOption
{
    static unsigned long long muNameHash = 0x369AA9FC9BDA7A5E;
    static unsigned long long muTemplateHash = 0xE8CBB25AF0B05F86;

    eDeathConsequencesDifficulty DeathConsequencesDifficulty;
}
