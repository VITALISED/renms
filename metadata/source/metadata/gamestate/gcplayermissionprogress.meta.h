#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/gcplayermissionparticipant.meta.h>

class cGcPlayerMissionProgress
{
    static unsigned long long muNameHash = 0x1611798444BC0C13;
    static unsigned long long muTemplateHash = 0xC4054BE6D6E72C73;

    TkID<128> mMission;
    int miProgress;
    unsigned long long mui64Seed;
    unsigned long long mui64Data;
    cTkFixedArray<cGcPlayerMissionParticipant> maParticipants;
}
