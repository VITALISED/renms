#pragma once
#include <metadata/metadata_common.h>

class cGcThirdPersonAnimParams
{
    static unsigned long long muNameHash = 0x2AA340CCDBA01EAD;
    static unsigned long long muTemplateHash = 0x4BA36A3444947135;

    cTkVector2 mVelocity;
    cTkVector2 mVelocityXY;
    float mfVelocityY;
    float mfVelocityZ;
    cTkVector2 mMoveForce;
    float mfMoveForceApplied;
    cTkVector2 mAimDirection;
    float mfSpeed;
    float mfFoot;
    float mfHitLR;
    float mfHitFB;
    float mfLeanLR;
    float mfLeanFB;
    float mfAimPitch;
    float mfAimYaw;
    float mfTurnAngle;
    float mfDistanceFromGround;
    float mfUphill;
    float mfSlopeAngle;
    float mfTimeSinceJetpackEngaged;
}
