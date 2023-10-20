#pragma once
#include <metadata/metadata_common.h>
enum eDamageGivenDifficulty
{
    EDamageGivenDifficulty_High = 0,
    EDamageGivenDifficulty_Normal = 1,
    EDamageGivenDifficulty_Low = 2,
}

class cGcDamageGivenDifficultyOption
{
    static unsigned long long muNameHash = 0xCDF3A507A47FCD3;
    static unsigned long long muTemplateHash = 0x589112860941268A;

    eDamageGivenDifficulty DamageGivenDifficulty;
}
