#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/tkblackboarddefaultvaluefloat.meta.h>

class cGcBehaviourMaintainRangeFromTargetData
{
    static unsigned long long muNameHash = 0x7C8B3A3A3EEFC49F;
    static unsigned long long muTemplateHash = 0x8959480696CF2F28;

    TkID<128> mTargetKey;
    cTkBlackboardDefaultValueFloat MinDist;
    cTkBlackboardDefaultValueFloat MaxDist;
    bool mb2D;
    bool mbSucceedWhenInRange;
    float mfSpeedModifier;
    float mfAvoidCreaturesStrength;
}
