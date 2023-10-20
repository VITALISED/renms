#pragma once
#include <metadata/metadata_common.h>

class cGcGroundWormComponentData
{
    static unsigned long long muNameHash = 0x93C5F18EADCD6C3C;
    static unsigned long long muTemplateHash = 0x5D4EF68A1BE622F5;

    cTkFixedString<256,char> macLookJoint;
    cTkFixedString<256,char> macGrabJoint;
    TkID<128> mEmergeEffect;
    TkID<128> mSubmergeEffect;
    TkID<128> mEmergeShake;
    TkID<128> mRoarShake;
    float mfCollisionBodySize;
    float mfRumbleTime;
    float mfEmergeEffectTime;
    float mfEmergeDist;
    float mfSubmergeDist;
    float mfSubmergeDepth;
    float mfFlinchTime;
    float mfFlinchAngleMin;
    float mfFlinchAngleMax;
    float mfFlinchSmooth;
    TkID<128> mAttackDamageType;
    float mfAttackDamageRadius;
    float mfAttackAngle;
    float mfAttackDistMin;
    float mfAttackDistMax;
    float mfAttackCooldown;
    float mfRoarCooldown;
    float mfLungeStrength;
    float mfLungeAngleHead;
    float mfLungeAngleBase;
    float mfLungeBeginTime;
    float mfLungeEndTime;
    float mfLungeBlendInSpeed;
    float mfLungeBlendOutSpeed;
    float mfWindUpStrength;
    float mfWindUpAngleHead;
    float mfWindUpAngleBase;
    float mfRestTime;
    float mfTrackTime;
    float mfTurnSpeed;
    float mfEmergeLookBlendStart;
    float mfEmergeLookBlendEnd;
    float mfEmergeTime;
    float mfRearUpBeginDist;
    float mfRearUpEndDist;
}
