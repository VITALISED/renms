#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcBiomeListPerStarType
{
    static unsigned long long muNameHash = 0xFABB438AC71DAB8D;
    static unsigned long long muTemplateHash = 0xDB25A53E0EB949F6;

    cTkFixedArray<cGcBiomeList> maStarType;
    cGcBiomeList LushYellow;
    cGcBiomeList AbandonedYellow;
    cTkFixedArray<float> maLifeChance;
    cTkFixedArray<float> maAbandonedLifeChance;
    float mfConvertDeadToWeird;
}
