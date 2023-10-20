#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/basebuilding/npc/gcfreighterroomnpcspawncapacityentry.meta.h>

class cGcFreighterRoomNPCSpawnCapacities
{
    static unsigned long long muNameHash = 0xF9AE5C7D267CB35F;
    static unsigned long long muTemplateHash = 0xA461AD798F8E00FD;

    cTkDynamicArray<cGcFreighterRoomNPCSpawnCapacityEntry> maRoomSpawnCapacities;
}
