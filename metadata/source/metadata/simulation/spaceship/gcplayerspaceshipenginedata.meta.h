#pragma once
#include <metadata/metadata_common.h>

class cGcPlayerSpaceshipEngineData
{
    static unsigned long long muNameHash = 0x1C062102935FA221;
    static unsigned long long muTemplateHash = 0x8676B7E0F7721711;

    float mfThrustForce;
    float mfMaxSpeed;
    float mfMinSpeed;
    float mfFalloff;
    float mfMinSpeedForce;
    float mfBoostThrustForce;
    float mfBoostMaxSpeed;
    float mfBoostFalloff;
    float mfBoostingTurnDamp;
    float mfDirectionBrakeMin;
    float mfDirectionBrake;
    float mfReverseBrake;
    float mfOverspeedBrake;
    float mfLowSpeedTurnDamper;
    float mfTurnBrakeMin;
    float mfTurnBrakeMax;
    float mfTurnStrength;
    float mfRollAmount;
    float mfRollForce;
    float mfRollAutoTime;
    float mfBalanceTimeMin;
    float mfBalanceTimeMax;
    float mfFollowProportionalGain;
    float mfFollowDerivativeGain;
    float mfFollowIntegralGain;
    float mfFollowProportionalLimit;
    float mfFollowDerivativeLimit;
    float mfFollowIntegralLimit;
    float mfFollowIntegralDecay;
}
