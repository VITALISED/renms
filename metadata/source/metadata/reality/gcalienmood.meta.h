#pragma once
#include <metadata/metadata_common.h>
enum eMood
{
    EMood_Neutral = 0,
    EMood_Positive = 1,
    EMood_VeryPositive = 2,
    EMood_Negative = 3,
    EMood_VeryNegative = 4,
    EMood_Pity = 5,
    EMood_Sad = 6,
    EMood_Dead = 7,
    EMood_Confused = 8,
}

class cGcAlienMood
{
    static unsigned long long muNameHash = 0x9A637E59AB66BFB0;
    static unsigned long long muTemplateHash = 0x24CC01D94B6A1C1B;

    eMood Mood;
}
