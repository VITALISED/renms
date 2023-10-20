#pragma once
#include <metadata/metadata_common.h>

class cGcSimpleIkRecoilComponentData
{
    static unsigned long long muNameHash = 0xF516885AE98E72E8;
    static unsigned long long muTemplateHash = 0x53F711196A6BD582;

    cTkFixedString<256,char> macEndJoint;
    float mfHitReactDirectedMin;
    float mfHitReactDirectedMax;
    float mfHitReactRandomMin;
    float mfHitReactRandomMax;
    float mfAngleLimit;
    float mfMinHitReactTime;
    float mfRecoverTime;
    float mfActiveRange;
}
