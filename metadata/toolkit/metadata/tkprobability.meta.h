#pragma once
#include <metadata/metadata_common.h>
enum eProbability
{
    EProbability_Common = 0,
    EProbability_Uncommon = 1,
    EProbability_Rare = 2,
    EProbability_Extraordinary = 3,
}

class cTkProbability
{
    static unsigned long long muNameHash = 0x291E526240E013CC;
    static unsigned long long muTemplateHash = 0xEE55E2B6711F8A8D;

    eProbability Probability;
}
