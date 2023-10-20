#pragma once
#include <metadata/metadata_common.h>
enum eAbandonedFreighterMissionState
{
    EAbandonedFreighterMissionState_EndRoomComplete = 0,
    EAbandonedFreighterMissionState_CrewManifestRead = 1,
    EAbandonedFreighterMissionState_CaptainsLogRead = 2,
    EAbandonedFreighterMissionState_HazardOn = 3,
    EAbandonedFreighterMissionState_SlowWalkOn = 4,
    EAbandonedFreighterMissionState_OpenDoors = 5,
}

class cGcRewardSetAbandonedFreighterMissionState
{
    static unsigned long long muNameHash = 0xDEABEB9DAFEFB3D9;
    static unsigned long long muTemplateHash = 0x2C56AC8AB40CE6A7;

    eAbandonedFreighterMissionState AbandonedFreighterMissionState;
    bool mbSilent;
}
