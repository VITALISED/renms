#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcNPCInteractiveObjectState
{
    static unsigned long long muNameHash = 0x8D18F9F6D2A592B3;
    static unsigned long long muTemplateHash = 0xD19C0E4EBABA1360;

    TkID<128> mName;
    bool mbFaceSpawnDir;
    bool mbFaceNodeDir;
    bool mbFaceInvNodeDir;
    bool mbLookAtModel;
    cTkFixedString<64,char> macLookAtNode;
    bool mbFaceLookAt;
    bool mbMaintainLookAt;
    bool mbPlayIdles;
    bool mbCanConverse;
    cGcNPCPropType Prop;
    cGcNPCSeatedPosture SeatedPosture;
    float mfBlendTime;
    float mfEarlyOutTime;
    cTkDynamicArray<cGcNPCProbabilityAnimationData> maAnimations;
    float mfSpineAdjustAmount;
    int miMinAnims;
    int miMaxAnims;
    float mfMinTime;
    float mfMaxTime;
    cTkDynamicArray<cGcNPCInteractiveObjectStateTransition> maTransitions;
}
