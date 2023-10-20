#pragma once
#include <metadata/metadata_common.h>

class cGcMissionConditionElevation
{
    static unsigned long long muNameHash = 0xD66DAD0E4E6333FB;
    static unsigned long long muTemplateHash = 0xCFFE56D66B0CA;

    float mfHeightAboveSea;
    bool mbAllowInShip;
    bool mbTakeAmountFromSeasonData;
}
