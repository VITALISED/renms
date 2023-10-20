#pragma once
#include <metadata/metadata_common.h>

class cGcRewardProcTechProduct
{
    static unsigned long long muNameHash = 0x6D88488E4483F056;
    static unsigned long long muTemplateHash = 0xF59F20CCE22DC03C;

    TkID<256> mGroup;
    int miWeightedChanceNormal;
    int miWeightedChanceRare;
    int miWeightedChanceEpic;
    int miWeightedChanceLegendary;
    bool mbForceRelevant;
    bool mbForceQualityRelevant;
}
