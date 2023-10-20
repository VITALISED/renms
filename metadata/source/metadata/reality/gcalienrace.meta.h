#pragma once
#include <metadata/metadata_common.h>
enum eAlienRace
{
    EAlienRace_Traders = 0,
    EAlienRace_Warriors = 1,
    EAlienRace_Explorers = 2,
    EAlienRace_Robots = 3,
    EAlienRace_Atlas = 4,
    EAlienRace_Diplomats = 5,
    EAlienRace_Exotics = 6,
    EAlienRace_None = 7,
}

class cGcAlienRace
{
    static unsigned long long muNameHash = 0x9A5ABD2833971D0E;
    static unsigned long long muTemplateHash = 0x86B962D12194C137;

    eAlienRace AlienRace;
}
