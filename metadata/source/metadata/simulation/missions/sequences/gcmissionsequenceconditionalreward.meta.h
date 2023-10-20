#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/missions/types/gcmissionconditiontest.meta.h>

class cGcMissionSequenceConditionalReward
{
    static unsigned long long muNameHash = 0x4A3E875FBE0AEA1D;
    static unsigned long long muTemplateHash = 0xD0089B6F057AF2B;

    TkID<128> mRewardIfTrue;
    TkID<128> mRewardIfFalse;
    cGcMissionConditionTest ConditionTest;
    cTkDynamicArray<cTkClassPointer> maConditions;
    cTkFixedString<128,char> macDebugText;
}
