#pragma once
#include <metadata/metadata_common.h>

class cTkDynamicChainComponentData
{
    static unsigned long long muNameHash = 0x380D960FAA1BF837;
    static unsigned long long muTemplateHash = 0x2DD2D2E517ED0C52;

    float mfAngularLimit;
    float mfTwistLimit;
    float mfMotorStrengthCone;
    float mfMotorStrengthTwist;
    float mfMaxMotorForce;
    float mfGravity;
    float mfAirThickness;
    float mfVertAirThickness;
    float mfWindStrength;
    float mfLinearDamping;
    float mfAngularDamping;
    float mfInitialBodyMass;
    float mfBodyMassChange;
    bool mbWeightByJointLength;
    cTkDynamicArray<cTkFixedString<32,char>> maIgnoreJoints;
}
