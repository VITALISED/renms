#pragma once
#include <metadata/metadata_common.h>
enum eCombatType
{
    ECombatType_GroundCombat = 0,
    ECombatType_SpaceCombat = 1,
    ECombatType_FiendCombat = 2,
    ECombatType_BigFishFiendCombat = 3,
    ECombatType_CorruptedSentinelCombat = 4,
    ECombatType_GroundWormCombat = 5,
    ECombatType_RewardEncounter = 6,
}

class cGcMissionConditionInCombat
{
    static unsigned long long muNameHash = 0x326A8803E3B79519;
    static unsigned long long muTemplateHash = 0xC05E3E5570BE569E;

    eCombatType CombatType;
    TkID<256> mOverrideOSDMessage;
    bool mbCheckAllFireteamMembers;
    bool mbEncouragesFightingSentinels;
}
