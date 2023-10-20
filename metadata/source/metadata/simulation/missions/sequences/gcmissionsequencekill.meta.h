#pragma once
#include <metadata/metadata_common.h>
enum eKillTarget
{
    EKillTarget_Robots = 0,
    EKillTarget_Drones = 1,
    EKillTarget_Quads = 2,
    EKillTarget_Walkers = 3,
    EKillTarget_Predators = 4,
    EKillTarget_Creatures = 5,
    EKillTarget_Pirates = 6,
    EKillTarget_Traders = 7,
    EKillTarget_Fiends = 8,
    EKillTarget_HazardousFlora = 9,
    EKillTarget_Worms = 10,
}

class cGcMissionSequenceKill
{
    static unsigned long long muNameHash = 0xF2F929BD28DDCD6B;
    static unsigned long long muTemplateHash = 0x79A38FA0B68F95E0;

    cTkFixedString<128,char> macMessage;
    eKillTarget KillTarget;
    int miAmountMin;
    int miAmountMax;
    cTkFixedString<128,char> macDebugText;
}
