#pragma once
#include <metadata/metadata_common.h>

class cGcMissionConditionRefinerActive
{
    static unsigned long long muNameHash = 0x1B95D5FDE04FECD9;
    static unsigned long long muTemplateHash = 0xD73F36F557B264E8;

    bool mbHasFuel;
    TkID<256> mActiveRecipe;
    int miAmountToMake;
}
