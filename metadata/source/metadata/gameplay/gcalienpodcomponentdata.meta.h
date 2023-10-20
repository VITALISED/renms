#pragma once
#include <metadata/metadata_common.h>

class cGcAlienPodComponentData
{
    static unsigned long long muNameHash = 0x71B7896BF38DAAE4;
    static unsigned long long muTemplateHash = 0x42BCABB3F2D44B9B;

    float mfAgroRate;
    float mfAgroMovement;
    float mfAgroMovementRange;
    float mfAgroTorch;
    float mfAgroTorchRange;
    float mfAgroTorchFOV;
    float mfAgroThreshold;
    float mfAgroThresholdOffscreen;
    float mfAgroSpookValue;
    float mfAgroSpookTime;
    float mfAgroSpookTimeMin;
    float mfAgroSpookTimeMax;
    float mfGlowIntensityMin;
    float mfGlowIntensityMax;
    float mfInstaAgroDistance;
    float mfGunfireAgro;
    float mfGunfireAgroRange;
}
