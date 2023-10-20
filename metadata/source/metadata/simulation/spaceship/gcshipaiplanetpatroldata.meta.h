#pragma once
#include <metadata/metadata_common.h>

class cGcShipAIPlanetPatrolData
{
    static unsigned long long muNameHash = 0xB7FEFB0DFC120BF4;
    static unsigned long long muTemplateHash = 0x1359BFE0E49D8680;

    TkID<128> mSquad;
    float mfPlayerOffset;
    float mfPlayerFalloff;
    float mfPathOffset;
    float mfWaypointDistance;
    float mfPathSpeed;
    float mfAlongPathForce;
    float mfToPathForce;
    float mfBrakeForce;
    float mfAlignForce;
}
