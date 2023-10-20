#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcCreatureRidingData
{
    static unsigned long long muNameHash = 0xCBC8926C6C9D9A51;
    static unsigned long long muTemplateHash = 0xAEDEBE610D3F2531;

    cTkFixedString<256,char> macJointName;
    cTkFixedString<256,char> macAdditionalScaleJoint;
    cTkVector3 mOffset;
    cTkVector3 mRotationOffset;
    cTkVector3 mVROffset;
    float mfHeadCounterRotation;
    float mfUprightStrength;
    bool mbLegSpread;
    float mfScaleForNeutralLegSpread;
    float mfScaleForMinLegSpread;
    float mfScaleForMaxLegSpread;
    bool mbRequiresMatchingPartModifier;
    cTkDynamicArray<cGcCreatureRidingPartModifier> maPartModifiers;
    TkID<128> mIdleRidingAnim;
    TkID<128> mDefaultRidingAnim;
    cTkDynamicArray<cGcCreatureRidingAnimation> maRidingAnims;
}
