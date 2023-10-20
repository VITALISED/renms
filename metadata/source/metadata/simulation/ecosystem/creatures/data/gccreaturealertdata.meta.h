#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcCreatureAlertData
{
    static unsigned long long muNameHash = 0xFFF2D3D18F84C008;
    static unsigned long long muTemplateHash = 0x8344B26B24BE8FFF;

    cGcCreatureTypes AlertTarget;
    cGcCreatureTypes AlertInitiator;
    float mfHearingRange;
    float mfSightRange;
    float mfSightAngle;
    float mfFleeRange;
}
