#pragma once
#include <metadata/metadata_common.h>

class cGcShipAIAttackData
{
    static unsigned long long muNameHash = 0xA9C402167AF9D69B;
    static unsigned long long muTemplateHash = 0xE631E6FFCC918379;

    TkID<128> mId;
    float mfGunDispersionAngle;
    float mfGunFireRate;
    float mfLaserHealthPoint;
    float mfAttackWeaponRange;
    float mfAttackAngle;
    float mfAttackShootWaitTime;
    float mfAttackShootTimeMin;
    float mfAttackShootTimeMax;
    float mfAttackReadyTime;
    float mfAttackMaxTime;
    float mfAttackApproachOffset;
    float mfAttackApproachMinRange;
    float mfAttackApproachMaxRange;
    float mfAttackTooCloseRange;
    float mfAttackFlybyOffset;
    float mfAttackBoostTimeToRange;
    float mfAttackBoostRange;
    float mfAttackBoostAngle;
    float mfAttackTurnMultiplier;
    float mfAttackMaxPlanetHeight;
    float mfAttackTurnMultiplierMax;
    float mfAttackTurnMaxMinTime;
    float mfAttackTurnMaxTimeRange;
    int miNumHitsBeforeBail;
    int miNumHitsBeforeReposition;
    float mfFleeBrake;
    float mfFleeBoost;
    float mfFleeBrakeTime;
    float mfFleeRepositionTime;
    float mfFleeRepositionAngleMin;
    float mfFleeRepositionAngleMax;
    float mfFleeUrgentBrake;
    float mfFleeUrgentBoost;
    float mfFleeUrgentBrakeTime;
    float mfFleeRepositionUrgentTime;
    float mfFleeRepositionUrgentAngleMin;
    float mfFleeRepositionUrgentAngleMax;
    float mfFleeRange;
    float mfFleeMinTime;
    float mfFleeMaxTime;
    float mfFleeUrgentRange;
    float mfPlanetFleeHeightExtra;
    float mfAttackTargetMinRange;
    float mfAttackTargetMaxRange;
    float mfAttackTargetOffsetMin;
    float mfAttackTargetOffsetMax;
    float mfAttackTargetSwitchTargetTime;
}
