#pragma once
#include <metadata/metadata_common.h>
enum eCharacterState
{
    ECharacterState_Idle = 0,
    ECharacterState_Jog = 1,
    ECharacterState_JogUphill = 2,
    ECharacterState_JogDownhill = 3,
    ECharacterState_SteepSlope = 4,
    ECharacterState_Sliding = 5,
    ECharacterState_Run = 6,
    ECharacterState_Airborne = 7,
    ECharacterState_JetpackBoost = 8,
    ECharacterState_RocketBoots = 9,
    ECharacterState_Riding = 10,
    ECharacterState_Swimming = 11,
    ECharacterState_SwimmingJetpack = 12,
    ECharacterState_Death = 13,
    ECharacterState_FullBodyOverride = 14,
    ECharacterState_InSpace = 15,
    ECharacterState_LowGWalk = 16,
    ECharacterState_LowGRun = 17,
}

class cGcPlayerCharacterStateType
{
    static unsigned long long muNameHash = 0xDACE1F471447B685;
    static unsigned long long muTemplateHash = 0xFFA0D6143FE0142C;

    eCharacterState CharacterState;
}
