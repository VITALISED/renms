#pragma once
#include <metadata/metadata_common.h>
enum eRewardInventoryOverride
{
    ERewardInventoryOverride_None = 0,
    ERewardInventoryOverride_Suit = 1,
    ERewardInventoryOverride_Ship = 2,
    ERewardInventoryOverride_Vehicle = 3,
    ERewardInventoryOverride_Freighter = 4,
}

class cGcMissionSequenceReward
{
    static unsigned long long muNameHash = 0x7471FD77815538C2;
    static unsigned long long muTemplateHash = 0x3589DA89D687D2BD;

    cTkFixedString<128,char> macMessage;
    TkID<128> mReward;
    bool mbDoMissionBoardOverride;
    bool mbSilent;
    eRewardInventoryOverride RewardInventoryOverride;
    cTkFixedString<128,char> macDebugText;
}
