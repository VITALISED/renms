#pragma once
#include <metadata/metadata_common.h>
enum eNPCHabitationType
{
    ENPCHabitationType_WeaponsExpert = 0,
    ENPCHabitationType_Farmer = 1,
    ENPCHabitationType_Builder = 2,
    ENPCHabitationType_Vehicles = 3,
    ENPCHabitationType_Scientist = 4,
}

class cGcNPCHabitationType
{
    static unsigned long long muNameHash = 0x2A6BB71EAF092577;
    static unsigned long long muTemplateHash = 0xFDB46411B06AA1C;

    eNPCHabitationType NPCHabitationType;
}
