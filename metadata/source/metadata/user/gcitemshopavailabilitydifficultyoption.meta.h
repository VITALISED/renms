#pragma once
#include <metadata/metadata_common.h>
enum eItemShopAvailabilityDifficulty
{
    EItemShopAvailabilityDifficulty_High = 0,
    EItemShopAvailabilityDifficulty_Normal = 1,
    EItemShopAvailabilityDifficulty_Low = 2,
}

class cGcItemShopAvailabilityDifficultyOption
{
    static unsigned long long muNameHash = 0x9E64FF6ABCCC176A;
    static unsigned long long muTemplateHash = 0x45E28131CA26A14B;

    eItemShopAvailabilityDifficulty ItemShopAvailabilityDifficulty;
}
