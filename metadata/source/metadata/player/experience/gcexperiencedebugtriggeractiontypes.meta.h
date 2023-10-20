#pragma once
#include <metadata/metadata_common.h>
enum eExperienceDebugTriggerAction
{
    EExperienceDebugTriggerAction_None = 0,
    EExperienceDebugTriggerAction_Drones = 1,
    EExperienceDebugTriggerAction_FlyBy = 2,
    EExperienceDebugTriggerAction_FrigateFlyByBegin = 3,
    EExperienceDebugTriggerAction_FrigateFlyByEnd = 4,
    EExperienceDebugTriggerAction_PirateCargoAttack = 5,
    EExperienceDebugTriggerAction_PirateRaid = 6,
    EExperienceDebugTriggerAction_FreighterAttack = 7,
    EExperienceDebugTriggerAction_SpawnShips = 8,
    EExperienceDebugTriggerAction_LaunchShips = 9,
    EExperienceDebugTriggerAction_Mechs = 10,
    EExperienceDebugTriggerAction_SpaceBattle = 11,
    EExperienceDebugTriggerAction_RespawnInShip = 12,
    EExperienceDebugTriggerAction_DebugWalker = 13,
    EExperienceDebugTriggerAction_DebugWalkerTitanFall = 14,
    EExperienceDebugTriggerAction_SpawnNexus = 15,
    EExperienceDebugTriggerAction_Freighters = 16,
    EExperienceDebugTriggerAction_NPCs = 17,
    EExperienceDebugTriggerAction_Sandworm = 18,
    EExperienceDebugTriggerAction_SpacePOI = 19,
    EExperienceDebugTriggerAction_BackgroundSpaceEncounter = 20,
    EExperienceDebugTriggerAction_Creatures = 21,
    EExperienceDebugTriggerAction_CameraPath = 22,
    EExperienceDebugTriggerAction_SummonFleet = 23,
    EExperienceDebugTriggerAction_SummonSquadron = 24,
    EExperienceDebugTriggerAction_ResetScene = 25,
    EExperienceDebugTriggerAction_ResetPlayerPos = 26,
    EExperienceDebugTriggerAction_CameraSpin = 27,
    EExperienceDebugTriggerAction_SpawnEnemyShips = 28,
    EExperienceDebugTriggerAction_PetHappy = 29,
    EExperienceDebugTriggerAction_PetSad = 30,
    EExperienceDebugTriggerAction_PetFollow = 31,
    EExperienceDebugTriggerAction_PetFollowClose = 32,
    EExperienceDebugTriggerAction_PetRest = 33,
    EExperienceDebugTriggerAction_PetNatural = 34,
    EExperienceDebugTriggerAction_PetMine = 35,
    EExperienceDebugTriggerAction_PetMineAndDeposit = 36,
    EExperienceDebugTriggerAction_RidePet = 37,
    EExperienceDebugTriggerAction_Normandy = 38,
    EExperienceDebugTriggerAction_LivingFrigate = 39,
    EExperienceDebugTriggerAction_UpgradeSettlement = 40,
}

class cGcExperienceDebugTriggerActionTypes
{
    static unsigned long long muNameHash = 0x902E6B8A4F1B75A6;
    static unsigned long long muTemplateHash = 0xE55FAD85F8721A06;

    eExperienceDebugTriggerAction ExperienceDebugTriggerAction;
}
