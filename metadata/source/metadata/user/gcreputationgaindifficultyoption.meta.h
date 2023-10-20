#pragma once
#include <metadata/metadata_common.h>
enum eReputationGainDifficulty
{
    EReputationGainDifficulty_VeryFast = 0,
    EReputationGainDifficulty_Fast = 1,
    EReputationGainDifficulty_Normal = 2,
    EReputationGainDifficulty_Slow = 3,
}

class cGcReputationGainDifficultyOption
{
    static unsigned long long muNameHash = 0xA394F90C4AED36BD;
    static unsigned long long muTemplateHash = 0xEE494DB8A78148F1;

    eReputationGainDifficulty ReputationGainDifficulty;
}
