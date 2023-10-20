#pragma once
#include <metadata/metadata_common.h>
enum eNPCTrigger
{
    ENPCTrigger_None = 0,
    ENPCTrigger_Idle = 1,
    ENPCTrigger_Greet = 2,
    ENPCTrigger_Mood = 3,
    ENPCTrigger_StartDead = 4,
    ENPCTrigger_Talk_Start = 5,
    ENPCTrigger_Talk_Stop = 6,
    ENPCTrigger_Interact_Start = 7,
    ENPCTrigger_Interact_Stop = 8,
    ENPCTrigger_Interact_BeginHold = 9,
    ENPCTrigger_Interact_CancelHold = 10,
    ENPCTrigger_LookAt_Player_Start = 11,
    ENPCTrigger_LookAt_Player_Stop = 12,
    ENPCTrigger_SetProp = 13,
    ENPCTrigger_Interact_StartFromRemote = 14,
}

class cGcNPCTriggerTypes
{
    static unsigned long long muNameHash = 0xED4A21D9F7E3058B;
    static unsigned long long muTemplateHash = 0x34827E14E7CDCAFA;

    eNPCTrigger NPCTrigger;
}
