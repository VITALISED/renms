#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/npcs/gcnpcprobabilityanimationdata.meta.h>

class cGcNPCAnimationList
{
    static unsigned long long muNameHash = 0xE02B8846C8E8134E;
    static unsigned long long muTemplateHash = 0x2720461AD89C2C54;

    cTkDynamicArray<cGcNPCProbabilityAnimationData> maAnimations;
}
