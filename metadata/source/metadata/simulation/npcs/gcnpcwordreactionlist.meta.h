#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/npcs/gcnpcprobabilitywordreactiondata.meta.h>

class cGcNPCWordReactionList
{
    static unsigned long long muNameHash = 0x53C414A21BE5AF34;
    static unsigned long long muTemplateHash = 0x81C7026487638117;

    cTkDynamicArray<cGcNPCProbabilityWordReactionData> maReactions;
}
