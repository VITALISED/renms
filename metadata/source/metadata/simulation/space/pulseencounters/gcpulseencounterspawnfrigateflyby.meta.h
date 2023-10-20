#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/gcfrigateflybytype.meta.h>
#include <metadata/simulation/player/gcplayercommunicatormessage.meta.h>

class cGcPulseEncounterSpawnFrigateFlyby
{
    static unsigned long long muNameHash = 0x409E4BD41C6295C9;
    static unsigned long long muTemplateHash = 0x997EFD1FBFF7CE9F;

    cGcFrigateFlybyType FlybyType;
    TkID<256> mCommunicatorOSDLocId;
    cGcPlayerCommunicatorMessage CommunicatorMessage;
}
