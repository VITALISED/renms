#pragma once
#include <metadata/metadata_common.h>
#include <?>
enum eRequirement
{
    ERequirement_CanLearn = 0,
    ERequirement_CanSpeak = 1,
}

class cGcCostWordKnowledge
{
    static unsigned long long muNameHash = 0x67494CEE3CE0F9F6;
    static unsigned long long muTemplateHash = 0xC4F9F786BC08F74;

    cGcAlienRace Race;
    eRequirement Requirement;
}
