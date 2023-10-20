#pragma once
#include <metadata/metadata_common.h>

class cGcCharacterLookAtData
{
    static unsigned long long muNameHash = 0x566CA1D9F6501832;
    static unsigned long long muTemplateHash = 0x4955099D564BF21D;

    float mfInteractionLookAtRadius;
    float mfCreatureLookAtRadius;
    float mfSpaceshipLookAtRadius;
    float mfLookAtRunGlanceMinTime;
    float mfLookAtRunGlanceMaxTime;
    float mfLookAtRunMinTime;
    float mfLookAtRunMaxTime;
    float mfLookAtTargetGlanceMinTime;
    float mfLookAtTargetGlanceMaxTime;
    float mfLookAtTargetWaitMinTime;
    float mfLookAtTargetWaitMaxTime;
    float mfLookAtMaxYaw;
    float mfLookAtMaxPitch;
}
