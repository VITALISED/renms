#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>

class cTkAnimationComponentData
{
    static unsigned long long muNameHash = 0x379CFCF1CE84CBAA;
    static unsigned long long muTemplateHash = 0xB5263393C2F176F4;

    cTkAnimationData Idle;
    cTkDynamicArray<cTkAnimationData> maAnims;
    cTkDynamicArray<cTkAnimBlendTree> maTrees;
    bool mbNetSyncAnimations;
    cTkDynamicArray<cTkAnimJointLODData> maJointLODOverrides;
}
