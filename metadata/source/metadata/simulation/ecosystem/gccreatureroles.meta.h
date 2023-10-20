#pragma once
#include <metadata/metadata_common.h>
enum eCreatureRole
{
    ECreatureRole_None = 0,
    ECreatureRole_Predator = 1,
    ECreatureRole_PlayerPredator = 2,
    ECreatureRole_Prey = 3,
    ECreatureRole_Passive = 4,
    ECreatureRole_Bird = 5,
    ECreatureRole_FishPrey = 6,
    ECreatureRole_FishPredator = 7,
    ECreatureRole_Butterfly = 8,
    ECreatureRole_Robot = 9,
    ECreatureRole_Pet = 10,
}

class cGcCreatureRoles
{
    static unsigned long long muNameHash = 0xA8AB3ECD5F81E80C;
    static unsigned long long muTemplateHash = 0xEAA141147D899B8;

    eCreatureRole CreatureRole;
}
