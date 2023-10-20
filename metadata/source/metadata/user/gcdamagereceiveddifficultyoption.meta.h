#pragma once
#include <metadata/metadata_common.h>
enum eDamageReceivedDifficulty
{
    EDamageReceivedDifficulty_None = 0,
    EDamageReceivedDifficulty_Low = 1,
    EDamageReceivedDifficulty_Normal = 2,
    EDamageReceivedDifficulty_High = 3,
}

class cGcDamageReceivedDifficultyOption
{
    static unsigned long long muNameHash = 0x9065C0FF676A75B3;
    static unsigned long long muTemplateHash = 0xC9A9869EA0CA2FB;

    eDamageReceivedDifficulty DamageReceivedDifficulty;
}
