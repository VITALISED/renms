#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/basebuilding/gcnpchabitationtype.meta.h>

class cGcCostNPCHabitation
{
    static unsigned long long muNameHash = 0x6FDD00442DB9926C;
    static unsigned long long muTemplateHash = 0x967AAA5F1ABBD644;

    cGcNPCHabitationType NPCHabitationType;
    bool mbMustBeInhabited;
}
