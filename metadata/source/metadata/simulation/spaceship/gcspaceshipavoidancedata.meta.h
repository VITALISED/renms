#pragma once
#include <metadata/metadata_common.h>

class cGcSpaceshipAvoidanceData
{
    static unsigned long long muNameHash = 0xE607B9EEA91E2AD5;
    static unsigned long long muTemplateHash = 0x406F4438F098A30D;

    int miNumRays;
    float mfRayMinRange;
    float mfRaySpeedTime;
    float mfForce;
    float mfStartRadiusMultiplier;
    float mfEndRadiusMultiplier;
    float mfSpeedInterp;
    float mfSpeedInterpMinSpeed;
    float mfSpeedInterpRange;
}
