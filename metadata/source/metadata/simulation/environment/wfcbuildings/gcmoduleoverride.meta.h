#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcModuleOverride
{
    static unsigned long long muNameHash = 0x2ABA38292ED14515;
    static unsigned long long muTemplateHash = 0x426EFE251C152DC5;

    TkID<128> mModule;
    float mfProbabilityMultiplier;
    float mfOriginalSceneProbability;
    cTkDynamicArray<cGcWeightedResource> maScenes;
}
