#pragma once
#include <metadata/metadata_common.h>
enum eIncrementor
{
    EIncrementor_None = 0,
    EIncrementor_Resource = 1,
    EIncrementor_ResourceAway = 2,
    EIncrementor_HeavyAir = 3,
    EIncrementor_Drone = 4,
    EIncrementor_Deer = 5,
    EIncrementor_DeerScan = 6,
    EIncrementor_DeerWords = 7,
    EIncrementor_DeerWordsAway = 8,
    EIncrementor_Diplo = 9,
    EIncrementor_DiploScan = 10,
    EIncrementor_DiploWords = 11,
    EIncrementor_DiploWordsAway = 12,
    EIncrementor_Flyby = 13,
    EIncrementor_Beast = 14,
    EIncrementor_Wingmen = 15,
    EIncrementor_Scouts = 16,
    EIncrementor_Fleet = 17,
    EIncrementor_Attackers = 18,
    EIncrementor_AttackersFromBehind = 19,
    EIncrementor_Flee = 20,
    EIncrementor_RemoveFleet = 21,
    EIncrementor_Fighters = 22,
    EIncrementor_PostFighters = 23,
    EIncrementor_Escape = 24,
    EIncrementor_Warp = 25,
}

class cGcCreatureSpawnEnum
{
    static unsigned long long muNameHash = 0xF1142B73FBEC2939;
    static unsigned long long muTemplateHash = 0xC4D3D498FA5EAF4B;

    eIncrementor Incrementor;
}
