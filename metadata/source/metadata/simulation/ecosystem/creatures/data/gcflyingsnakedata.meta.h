#pragma once
#include <metadata/metadata_common.h>

class cGcFlyingSnakeData
{
    static unsigned long long muNameHash = 0x8AE34D6AD8F2EB14;
    static unsigned long long muTemplateHash = 0x912B8C84F2D13E72;

    float mfCircleSpeed;
    float mfApproachBaitSpeed;
    float mfDefaultCircleDistance;
    float mfBarrelRollSpawnDelay;
    float mfBarrelRollCount;
    float mfBarrelRollSpeed;
    float mfRiseDelay;
    float mfRiseHeight;
    float mfRiseTime;
    float mfAirThickness;
    float mfWindForce;
    float mfTailStiffness;
    float mfTwistLimit;
    float mfAltitudeSinPeriod;
    float mfAltitudeSinAmp;
    float mfAscendDescendSpeed;
}
