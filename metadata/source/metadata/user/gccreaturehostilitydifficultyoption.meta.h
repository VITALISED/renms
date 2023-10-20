#pragma once
#include <metadata/metadata_common.h>
enum eCreatureHostilityDifficulty
{
    ECreatureHostilityDifficulty_NeverAttack = 0,
    ECreatureHostilityDifficulty_AttackIfProvoked = 1,
    ECreatureHostilityDifficulty_FullEcosystem = 2,
}

class cGcCreatureHostilityDifficultyOption
{
    static unsigned long long muNameHash = 0x2B740202A0E2CC57;
    static unsigned long long muTemplateHash = 0xD86131FEFF826FFC;

    eCreatureHostilityDifficulty CreatureHostilityDifficulty;
}
