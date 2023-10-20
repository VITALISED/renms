#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcParticleAction
{
    static unsigned long long muNameHash = 0x88C11D6208F25864;
    static unsigned long long muTemplateHash = 0x692A75E313548729;

    TkID<128> mEffect;
    cTkFixedString<32,char> macJoint;
    bool mbExact;
    cGcBroadcastLevel FindRange;
}
