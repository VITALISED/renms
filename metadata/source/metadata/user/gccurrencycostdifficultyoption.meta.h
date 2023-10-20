#pragma once
#include <metadata/metadata_common.h>
enum eCurrencyCostDifficulty
{
    ECurrencyCostDifficulty_Free = 0,
    ECurrencyCostDifficulty_Cheap = 1,
    ECurrencyCostDifficulty_Normal = 2,
    ECurrencyCostDifficulty_Expensive = 3,
}

class cGcCurrencyCostDifficultyOption
{
    static unsigned long long muNameHash = 0x788E938DA3146A0E;
    static unsigned long long muTemplateHash = 0xBA23ADBB7917F039;

    eCurrencyCostDifficulty CurrencyCostDifficulty;
}
