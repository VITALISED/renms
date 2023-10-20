#pragma once
#include <metadata/metadata_common.h>
#include <?>
enum eGrabType
{
    EGrabType_Default = 0,
    EGrabType_EjectHandle = 1,
    EGrabType_ControlStickLeft = 2,
    EGrabType_ControlStickRight = 3,
}

class cGcGrabbableData
{
    static unsigned long long muNameHash = 0xEF85A351ABA84D63;
    static unsigned long long muTemplateHash = 0xC52A83607CC704B8;

    cTkFixedString<32,char> macLocatorName;
    float mfGrabRadius;
    float mfAttachTime;
    float mfReleaseRadius;
    float mfDetachTime;
    cGcHand Hand;
    cTkVector2 mRotationLimits;
    bool mbAllowOtherWayUp;
    bool mbAutoGrab;
    float mfToggleGrabTime;
    eGrabType GrabType;
    TkID<128> mHandPose;
    cTkFixedString<32,char> macMovementStartLocator;
    cTkFixedString<32,char> macMovementEndLocator;
    float mfMovementMaxSpeed;
    float mfMovementReturnSpeed;
    float mfMovementRequiredForActivation;
}
