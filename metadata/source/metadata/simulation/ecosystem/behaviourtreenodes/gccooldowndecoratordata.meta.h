#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/tkblackboarddefaultvaluefloat.meta.h>

class cGcCooldownDecoratorData
{
    static unsigned long long muNameHash = 0xB526D2F0411DDF0B;
    static unsigned long long muTemplateHash = 0x614385FBCB576753;

    TkID<128> mKey;
    cTkBlackboardDefaultValueFloat CooldownTime;
    cTkClassPointer mChild;
}
