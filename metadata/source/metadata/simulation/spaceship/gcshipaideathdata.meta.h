#pragma once
#include <metadata/metadata_common.h>

class cGcShipAIDeathData
{
    static unsigned long long muNameHash = 0x52329167EAE2541C;
    static unsigned long long muTemplateHash = 0x8E0A7AFFD011AE23;

    float mfDroneDeathTime;
    float mfDroneDeathForce;
    float mfDroneDeathBoomTotalTime;
    float mfDroneDeathOffset;
    int miDroneNumDeathBooms;
    float mfDroneDeathTimeout;
    float mfBrakeForce;
}
