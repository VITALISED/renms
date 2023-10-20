#pragma once
#include <metadata/metadata_common.h>

class cGcRewardTableItem
{
    static unsigned long long muNameHash = 0x743B54DBF617C58D;
    static unsigned long long muTemplateHash = 0xFA9F3918572932CA;

    float mfPercentageChance;
    cTkClassPointer mReward;
    cTkFixedString<64,char> macLabelID;
}
