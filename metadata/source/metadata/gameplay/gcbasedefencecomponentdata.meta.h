#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcBaseDefenceComponentData
{
    static unsigned long long muNameHash = 0x2D868A2A5696416C;
    static unsigned long long muTemplateHash = 0x2C014DBAB0A74271;

    cTkDynamicArray<cGcBaseDefenceTrigger> maTriggers;
    float mfLostUncertaintyThreshold;
    float mfSearchTime;
    bool mbPrioritiseThreats;
    float mfLaserRangeAnimateTime;
}
