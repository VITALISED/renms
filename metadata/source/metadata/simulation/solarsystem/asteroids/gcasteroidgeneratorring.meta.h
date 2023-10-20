#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcAsteroidGeneratorRing
{
    static unsigned long long muNameHash = 0x79403B157D846B70;
    static unsigned long long muTemplateHash = 0xFEAAE4F2806F9584;

    cGcAsteroidGeneratorAssignment Assignment;
    float mfLowerRadius;
    float mfUpperRadius;
    float mfPushRadius;
    int miOffBalance;
    cTkVector3 mRotation;
    float mfUSpread;
    float mfPushAmount;
    bool mbFlipPush;
}
