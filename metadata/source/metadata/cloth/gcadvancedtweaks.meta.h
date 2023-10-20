#pragma once
#include <metadata/metadata_common.h>

class cGcAdvancedTweaks
{
    static unsigned long long muNameHash = 0x1C1691C0F8971C4A;
    static unsigned long long muTemplateHash = 0x6E9D7EAB573C6CD6;

    float mfParticleKillSpeed;
    float mfParticleKillSpeedWrtFixed;
    float mfEdgeMultiplierForTangentI;
    float mfEdgeMultiplierForTangentJ;
    float mfRenderNormalMultiplier;
    float mfStretchUvsToHideTextureEdges;
}
