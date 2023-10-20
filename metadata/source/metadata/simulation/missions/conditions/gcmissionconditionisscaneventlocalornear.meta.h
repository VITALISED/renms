#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/missions/conditions/gcmissionconditionisscaneventlocal.meta.h>

class cGcMissionConditionIsScanEventLocalOrNear
{
    static unsigned long long muNameHash = 0xE9A41D09A14F59E1;
    static unsigned long long muTemplateHash = 0x77E2096FF7044EE6;

    cGcMissionConditionIsScanEventLocal Local;
    float mfMaxDistance;
}
