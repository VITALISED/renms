#pragma once
#include <metadata/metadata_common.h>
enum eAIFaction
{
    EAIFaction_Player = 0,
    EAIFaction_Civilian = 1,
    EAIFaction_Pirate = 2,
    EAIFaction_Police = 3,
    EAIFaction_Creature = 4,
}

class cGcRealityCommonFactions
{
    static unsigned long long muNameHash = 0xA57475D6E3E6E9A5;
    static unsigned long long muTemplateHash = 0xF861B887610499B7;

    eAIFaction AIFaction;
}
