#pragma once
#include <metadata/metadata_common.h>

class cTkCreatureTailJoints
{
    static unsigned long long muNameHash = 0x38D7F8085AD4CE3;
    static unsigned long long muTemplateHash = 0xC6CBA4BB1305622B;

    cTkFixedString<32,char> macStartJoint;
    cTkFixedString<32,char> macEndJoint;
    float mfInterpSpeedHead;
    float mfInterpSpeedTail;
    float mfPullSpeedMin;
    float mfPullSpeedMax;
    float mfStrengthX;
    float mfStrengthY;
    float mfStrengthZ;
    float mfSwimPhaseOffset;
}
