#pragma once
#include <metadata/metadata_common.h>
enum eFreighterBattleStatus
{
    EFreighterBattleStatus_None = 0,
    EFreighterBattleStatus_Active = 1,
    EFreighterBattleStatus_Joined = 2,
    EFreighterBattleStatus_Reward = 3,
}
#include <?>

class cGcMissionConditionFreighterBattle
{
    static unsigned long long muNameHash = 0xF8A296780D76172F;
    static unsigned long long muTemplateHash = 0xCB7F989D6DA449DA;

    eFreighterBattleStatus FreighterBattleStatus;
    int miFreighterBattleDistance;
    cTkEqualityEnum FreighterBattleTest;
}
