#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcNPCAnimationSetData
{
    static unsigned long long muNameHash = 0xF3A35A6135FAD505;
    static unsigned long long muTemplateHash = 0xE00D51FF9EA5A779;

    cTkDynamicArray<cGcNPCProbabilityAnimationData> maIdleAnimations;
    cTkDynamicArray<cGcNPCProbabilityAnimationData> maIdleFlavourAnimations;
    cTkDynamicArray<cGcNPCProbabilityAnimationData> maChatterAnimations;
    cTkDynamicArray<cGcNPCProbabilityAnimationData> maListenAnimations;
    cTkDynamicArray<cGcNPCProbabilityAnimationData> maGreetAnimations;
    cTkFixedArray<cGcNPCAnimationList> maMoodAnims;
    cTkFixedArray<TkID<128>> maMoodLoops;
}
