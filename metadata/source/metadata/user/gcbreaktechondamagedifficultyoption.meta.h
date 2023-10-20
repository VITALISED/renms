#pragma once
#include <metadata/metadata_common.h>
enum eBreakTechOnDamageProbability
{
    EBreakTechOnDamageProbability_None = 0,
    EBreakTechOnDamageProbability_Low = 1,
    EBreakTechOnDamageProbability_High = 2,
}

class cGcBreakTechOnDamageDifficultyOption
{
    static unsigned long long muNameHash = 0x1858CF2F851302AE;
    static unsigned long long muTemplateHash = 0x2C81FD0FE4E2CBFB;

    eBreakTechOnDamageProbability BreakTechOnDamageProbability;
}
