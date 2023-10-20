#pragma once
#include <metadata/metadata_common.h>

class cGcSpaceshipTravelData
{
    static unsigned long long muNameHash = 0x88C0028CC5F47D1D;
    static unsigned long long muTemplateHash = 0x6228F5D4E6A4CF1;

    TkID<128> mId;
    float mfMinSpeed;
    float mfMaxSpeed;
    float mfBoostSpeed;
    float mfForce;
    float mfMinSpeedForce;
    float mfTurnMin;
    float mfTurnMax;
    float mfDirectionBrake;
    float mfMaxSpeedBrake;
    float mfFalloff;
    float mfRoll;
    float mfMinHeight;
    float mfAvoidTime;
    bool mbHovering;
}
