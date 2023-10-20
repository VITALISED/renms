#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/basebuilding/gcnpchabitationtype.meta.h>

class cGcNPCHabitationComponentData
{
    static unsigned long long muNameHash = 0x340529EE9BE0F315;
    static unsigned long long muTemplateHash = 0x604F221F03B0371;

    TkID<128> mNPCSpawnLocator;
    cGcNPCHabitationType NPCHabitationType;
}
