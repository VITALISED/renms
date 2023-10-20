#pragma once
#include <metadata/metadata_common.h>
#include <metadata/animation/tkanimationdata.meta.h>
#include <metadata/animation/tkanimblendtree.meta.h>
#include <metadata/animation/tkanimjointloddata.meta.h>

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
