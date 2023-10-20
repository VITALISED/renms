#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcDroneData
{
    static unsigned long long muNameHash = 0xC42B2790FC61E0A9;
    static unsigned long long muTemplateHash = 0x56497BC5426DAD98;

    cGcDroneControlData Patrol;
    cGcDroneControlData Attack;
    cGcDroneControlData Search;
    cGcDroneControlData Scan;
    cGcDroneControlData Repair;
    cGcDroneControlData Summon;
    cGcDroneControlData ToCover;
    cGcDroneControlData Stun;
    cGcDroneControlData Friendly;
    cGcDroneControlData FriendlyFast;
    float mfCollisionAvoidOffset;
    float mfDronePatrolDistanceMin;
    float mfDronePatrolDistanceMax;
    float mfDronePatrolTargetDistance;
    float mfDronePatrolInspectDistanceMin;
    float mfDronePatrolInspectDistanceMax;
    float mfDronePatrolInspectTargetTime;
    float mfDronePatrolInspectSwitchTime;
    float mfDronePatrolInspectRadius;
    float mfDronePatrolRepelDistance;
    float mfDronePatrolRepelStrength;
    float mfDronePatrolHonkRadius;
    float mfDronePatrolHonkTime;
    int miDronePatrolHonkProbability;
    float mfDroneAlertTime;
    float mfAttackMoveLookDistanceRange;
    float mfAttackMoveLookDistanceMin;
    float mfAttackAngle;
    float mfAttackMinSpeed;
    float mfAttackActivateTime;
    float mfAttackBobAmount;
    float mfAttackBobRotation;
    float mfAttackMoveMinChoiceTime;
    float mfAttackMoveAngle;
    float mfAttackMaxDistanceFromAlert;
    float mfAttackAlertFailTime;
    cTkColour mEyeColourAlert;
    cTkColour mEyeColourSearch;
    cTkColour mEyeColourPatrol;
    TkID<128> mDamageEffect;
    float mfDamageEffectHealthPercentThreshold;
    float mfHideBehindCoverHealthPercentThreshold;
    float mfHideBehindCoverSearchRadius;
    bool mbEnableCoverPlacement;
    float mfCoverPlacementActivateTime;
    float mfCoverPlacementActivateTimeMaxRandomExtra;
    float mfCoverPlacementCooldownTime;
    float mfCoverPlacementMinDistanceFromTarget;
    float mfCoverPlacementMinDistanceFromSelf;
    float mfCoverPlacementMaxDistanceFromSelf;
    float mfCoverPlacementUpOffset;
    int miCoverPlacementMaxActiveCover;
    cGcSentinelResource CoverResource;
    float mfDroneSearchTime;
    float mfDroneSearchRadius;
    float mfDroneSearchPauseTime;
    float mfDroneSearchCriminalScanRadius;
    float mfDroneSearchCriminalScanRadiusWanted;
    float mfDroneSearchCriminalScanRadiusInShip;
    float mfDroneScanPlayerTime;
    float mfLeanAmount;
    float mfLeanSpeedMin;
    float mfLeanSpeedRange;
    float mfEyeOffset;
    float mfEyeFocusTime;
    int miEyeNumRandomsMin;
    int miEyeNumRandomsMax;
    float mfEyeTimeMin;
    float mfEyeTimeMax;
    float mfEyeAngleMax;
    float mfEngineDirSpeedMin;
    float mfEngineDirAngleMax;
}
