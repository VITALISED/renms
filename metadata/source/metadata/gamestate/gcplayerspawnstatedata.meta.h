#pragma once
#include <metadata/metadata_common.h>
enum eLastKnownPlayerState
{
    ELastKnownPlayerState_OnFoot = 0,
    ELastKnownPlayerState_InShip = 1,
    ELastKnownPlayerState_InStation = 2,
    ELastKnownPlayerState_AboardFleet = 3,
    ELastKnownPlayerState_InNexus = 4,
    ELastKnownPlayerState_AbandonedFreighter = 5,
    ELastKnownPlayerState_InShipLanded = 6,
}

class cGcPlayerSpawnStateData
{
    static unsigned long long muNameHash = 0x6F8C3831DC1540EC;
    static unsigned long long muTemplateHash = 0xC0D8ABF2503E00DC;

    cTkVector4 mPlayerPositionInSystem;
    cTkVector4 mPlayerTransformAt;
    cTkVector4 mPlayerDeathRespawnPositionInSystem;
    cTkVector4 mPlayerDeathRespawnTransformAt;
    cTkVector4 mShipPositionInSystem;
    cTkVector4 mShipTransformAt;
    eLastKnownPlayerState LastKnownPlayerState;
    cTkVector4 mFreighterPositionInSystem;
    cTkVector4 mFreighterTransformAt;
    cTkVector4 mFreighterTransformUp;
    cTkVector4 mAbandonedFreighterPositionInSystem;
    cTkVector4 mAbandonedFreighterTransformAt;
    cTkVector4 mAbandonedFreighterTransformUp;
}
