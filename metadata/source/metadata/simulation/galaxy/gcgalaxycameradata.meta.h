#pragma once
#include <metadata/metadata_common.h>

class cGcGalaxyCameraData
{
    static unsigned long long muNameHash = 0x76DA44862CDF100D;
    static unsigned long long muTemplateHash = 0xBEE72C5F9E9A4FE2;

    float mfCameraFOV;
    float mfMovementBlendRateFree;
    float mfMovementBlendRateLocked;
    float mfMovementBlendRateLookLocked;
    float mfLockTransitionRate;
    float mfLockedSpinSpeed;
    float mfLockedScaledPushSpeed;
    float mfLockedScaledElevationSpeed;
    float mfFreePanSpeed;
    float mfFreePanSpeedTurbo;
    float mfFreeUpDownSpeed;
    float mfFreeUpDownSpeedTurbo;
    float mfFreeRotateSpeed;
    float mfFreeElevationBlendRate;
    float mfZoomOutSpin;
    float mfZoomOutElevation;
    float mfZoomOutPushDist;
    float mfZoomOutRate;
    float mfZoomInRate;
    float mfMinZoomDistance;
    float mfMaxZoomDistance;
    float mfMinPushingZoomDistance;
    float mfMinPushingZoomDistanceScaler;
    float mfCameraShakeDriftClip;
    float mfCameraShakeDriftShift;
    float mfCameraShakeSmoothingRate;
    float mfCameraShakeMaximum;
}
