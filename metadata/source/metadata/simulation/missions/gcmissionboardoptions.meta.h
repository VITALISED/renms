#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/missions/types/gcmissiontype.meta.h>
#include <metadata/simulation/missions/types/gcmissiondifficulty.meta.h>
#include <metadata/simulation/missions/types/gcmissionfaction.meta.h>
enum eDefaultItemTypeForInitialWarp
{
    EDefaultItemTypeForInitialWarp_None = 0,
    EDefaultItemTypeForInitialWarp_PrimaryProduct = 1,
    EDefaultItemTypeForInitialWarp_PrimarySubstance = 2,
    EDefaultItemTypeForInitialWarp_SecondaryProduct = 3,
    EDefaultItemTypeForInitialWarp_SecondarySubstance = 4,
}

class cGcMissionBoardOptions
{
    static unsigned long long muNameHash = 0xDD272E15749CCDF5;
    static unsigned long long muTemplateHash = 0xFC68B7B7649C4567;

    cGcMissionType Type;
    cGcMissionDifficulty Difficulty;
    int miMinRank;
    bool mbCloseMissionGiver;
    bool mbIsGuildShopMission;
    bool mbIsPlanetProcMission;
    bool mbIsMultiplayerEventMission;
    TkID<128> mRewardPenaltyOnAbandon;
    cTkDynamicArray<cGcMissionFaction> maFaction;
    int miWeighting;
    bool mbIgnoreCalculatedObjective;
    TkID<256> mMultiplayerMissionInitialWarpScanEvent;
    cTkDynamicArray<TkID<256>> maDefaultItemInitialWarpScanEvents;
    eDefaultItemTypeForInitialWarp DefaultItemTypeForInitialWarp;
    cTkDynamicArray<TkID<128>> maBasePartBlueprints;
}
