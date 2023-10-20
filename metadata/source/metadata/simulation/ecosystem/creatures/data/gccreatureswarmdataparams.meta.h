#pragma once
#include <metadata/metadata_common.h>

class cGcCreatureSwarmDataParams
{
    static unsigned long long muNameHash = 0x691F170D5F26887A;
    static unsigned long long muTemplateHash = 0x7BCB779856C3ADF6;

    cTkDynamicArray<TkID<256>> maValidDescriptors;
    float mfCoherence;
    float mfAlignment;
    float mfSeparateStrength;
    float mfSpacing;
    float mfFollow;
    float mfRange;
    float mfMaxBankingAmount;
    float mfTurnRequiredForMaxBanking;
    float mfMaxPitchAmount;
    float mfUpwardMovementForMaxPitch;
    float mfFaceMoveDirStrength;
    bool mbFaceMoveDirYawOnly;
    bool mbCanLand;
    float mfLandAdjustDist;
    float mfLandClampBegin;
    float mfLandSlowDown;
    float mfTakeOffTime;
    float mfTakeOffStartSpeed;
    float mfTakeOffUpwardBoost;
    bool mbCanWalk;
    float mfWalkSpeed;
    float mfWalkTurnTime;
    float mfFlyTimeMin;
    float mfFlyTimeMax;
    float mfLandTimeMin;
    float mfLandTimeMax;
    float mfLandIdleTimeMin;
    float mfLandIdleTimeMax;
    float mfLandWalkTimeMin;
    float mfLandWalkTimeMax;
    float mfMaxSpeed;
    float mfAlignTime;
    float mfBankingTime;
    float mfSpringSmoothTime;
    bool mbApplyScaleToSpeed;
}
