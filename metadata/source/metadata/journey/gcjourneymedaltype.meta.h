#pragma once
#include <metadata/metadata_common.h>
enum eMedalType
{
    EMedalType_Standings = 0,
    EMedalType_Missions = 1,
    EMedalType_Words = 2,
    EMedalType_Systems = 3,
    EMedalType_Sentinels = 4,
    EMedalType_Pirates = 5,
    EMedalType_Plants = 6,
    EMedalType_Units = 7,
    EMedalType_RaceCreatures = 8,
    EMedalType_DistanceWarped = 9,
}

class cGcJourneyMedalType
{
    static unsigned long long muNameHash = 0x50569DD5AA245CF0;
    static unsigned long long muTemplateHash = 0xE4FDDBB5F69B5771;

    eMedalType MedalType;
}
