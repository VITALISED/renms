#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/tkblackboarddefaultvaluefloat.meta.h>
enum eBehaviourMoveSpeed
{
    EBehaviourMoveSpeed_Normal = 0,
    EBehaviourMoveSpeed_Fast = 1,
    EBehaviourMoveSpeed_Dynamic = 2,
}

class cGcBehaviourMoveToTargetData
{
    static unsigned long long muNameHash = 0x6CCA924D787E12E;
    static unsigned long long muTemplateHash = 0x48738CDF0B50AEFB;

    TkID<128> mTargetKey;
    cTkBlackboardDefaultValueFloat ArriveDist;
    eBehaviourMoveSpeed BehaviourMoveSpeed;
    float mfDynamicMoveSlowdownDistMul;
    float mfSpeedModifier;
    float mfAvoidCreaturesStrength;
}
