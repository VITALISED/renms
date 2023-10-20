#pragma once
#include <metadata/metadata_common.h>
enum eParticipantType
{
    EParticipantType_None = 0,
    EParticipantType_MissionGiver = 1,
    EParticipantType_MissionGiverReference = 2,
    EParticipantType_Primary = 3,
    EParticipantType_Secondary1 = 4,
    EParticipantType_Secondary2 = 5,
    EParticipantType_Secondary3 = 6,
    EParticipantType_Secondary4 = 7,
    EParticipantType_Secondary5 = 8,
    EParticipantType_Secondary6 = 9,
    EParticipantType_Secondary7 = 10,
    EParticipantType_Secondary8 = 11,
    EParticipantType_Secondary9 = 12,
}

class cGcPlayerMissionParticipantType
{
    static unsigned long long muNameHash = 0x233DD65A730CE9DF;
    static unsigned long long muTemplateHash = 0xECDE7A3D64070AF4;

    eParticipantType ParticipantType;
}
