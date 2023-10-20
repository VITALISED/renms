#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcCreatureRidingPartModifier
{
    static unsigned long long muNameHash = 0xB9A3955D41C87D67;
    static unsigned long long muTemplateHash = 0x66B10ABD887EC31F;

    TkID<256> mPartName;
    cTkFixedString<256,char> macJointName;
    float mfMinScale;
    float mfMaxScale;
    cTkFixedString<256,char> macAdditionalScaleJoint;
    bool mbBreakIfNotSelected;
    bool mbRelativeOffset;
    cTkVector3 mOffset;
    cTkVector3 mRotationOffset;
    cTkVector3 mVROffset;
    float mfHeadCounterRotation;
    float mfLegSpreadOffset;
    bool mbOverrideAnims;
    TkID<128> mIdleRidingAnim;
    TkID<128> mDefaultRidingAnim;
    cTkDynamicArray<cGcCreatureRidingAnimation> maRidingAnims;
}
