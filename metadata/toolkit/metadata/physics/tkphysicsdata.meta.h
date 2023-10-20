#pragma once
#include <metadata/metadata_common.h>

class cTkPhysicsData
{
    static unsigned long long muNameHash = 0x7446EB814E05B679;
    static unsigned long long muTemplateHash = 0x5329E7654CC6015B;

    float mfMass;
    float mfFriction;
    float mfRollingFriction;
    float mfAngularDamping;
    float mfLinearDamping;
    float mfGravity;
}
