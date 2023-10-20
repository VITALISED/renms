#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/tkblackboarddefaultvalueid.meta.h>
#include <metadata/simulation/tkblackboarddefaultvaluefloat.meta.h>
#include <metadata/simulation/tkblackboarddefaultvaluevector.meta.h>

class cGcBehaviourApplyDamageData
{
    static unsigned long long muNameHash = 0x88EF02AAFC25BCE6;
    static unsigned long long muTemplateHash = 0xB185E9E89F4E3649;

    cTkBlackboardDefaultValueId PlayerDamageType;
    cTkBlackboardDefaultValueFloat Radius;
    cTkBlackboardDefaultValueVector Offset;
}
