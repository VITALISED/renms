#pragma once
#include <metadata/metadata_common.h>
#include <metadata/audio/gcaudiowwiseevents.meta.h>

class cGcGrabPlayerComponentData
{
    static unsigned long long muNameHash = 0xDE6FCE33E294F619;
    static unsigned long long muTemplateHash = 0xB96D2F285E0ABF27;

    cTkFixedString<256,char> macLookJoint;
    cTkFixedString<256,char> macGrabJoint;
    TkID<128> mDefendAnim;
    TkID<128> mIdleAnim;
    TkID<128> mGrabAnim;
    TkID<128> mHoldAnim;
    TkID<128> mHitReactAnim;
    TkID<128> mPlayerGrabbedAnim;
    TkID<128> mDamageType;
    float mfDamageTime;
    float mfTriggerRange;
    cGcAudioWwiseEvents GrabBeginAudioEvent;
    cGcAudioWwiseEvents GrabEndAudioEvent;
    float mfLungeRadius;
    float mfGrabRadius;
    float mfGrabAttachStrength;
    float mfGrabBlendTime;
    float mfEjectImpulse;
    cTkVector3 mGrabOffset;
    float mfHoldTime;
    float mfCooldownTime;
    float mfRestTime;
    float mfMaxLookAngle;
    float mfBodgeInputAngle;
    float mfBodgeOutputAngle;
    float mfHitReactAnimChance;
    cTkVector2 mHitReactAngles;
    float mfActivateRange;
    float mfFocusRange;
    float mfTrackTime;
    cTkVector2 mLookAroundTrackTime;
    float mfLookAroundFineModifier;
    cTkVector2 mLookAtPlayerTime;
    float mfLookAtPlayerChance;
    cTkVector2 mLookAroundTime;
    cTkVector2 mLookAroundAngles;
    cTkVector2 mLookAroundAnglesFine;
    float mfSleepChance;
    cTkVector2 mSleepTime;
}
