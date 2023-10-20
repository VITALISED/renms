#pragma once
#include <metadata/metadata_common.h>
enum ePivotAnchorsTo
{
    EPivotAnchorsTo_Itself = 0,
    EPivotAnchorsTo_Parent = 1,
    EPivotAnchorsTo_Node = 2,
    EPivotAnchorsTo_NodeWithAnchor = 3,
}
enum eApplyMotionScaleIn
{
    EApplyMotionScaleIn_Disabled = 0,
    EApplyMotionScaleIn_Uniform = 1,
    EApplyMotionScaleIn_Itself = 2,
    EApplyMotionScaleIn_Parent = 3,
    EApplyMotionScaleIn_Component = 4,
}
enum eApplyMotionLimitsIn
{
    EApplyMotionLimitsIn_Disabled = 0,
    EApplyMotionLimitsIn_Uniform = 1,
    EApplyMotionLimitsIn_Itself = 2,
    EApplyMotionLimitsIn_Parent = 3,
    EApplyMotionLimitsIn_Component = 4,
}
enum eApplyAngularMotionScaleIn
{
    EApplyAngularMotionScaleIn_Disabled = 0,
    EApplyAngularMotionScaleIn_Uniform = 1,
    EApplyAngularMotionScaleIn_Itself = 2,
    EApplyAngularMotionScaleIn_Parent = 3,
    EApplyAngularMotionScaleIn_Component = 4,
}
enum eApplyAngularLimitsIn
{
    EApplyAngularLimitsIn_Disabled = 0,
    EApplyAngularLimitsIn_Itself = 1,
    EApplyAngularLimitsIn_Parent = 2,
    EApplyAngularLimitsIn_Component = 3,
}

class cGcSpringLink
{
    static unsigned long long muNameHash = 0x4B56CD3D914485CF;
    static unsigned long long muTemplateHash = 0x7DA8BF75E7FFBA01;

    bool mbEnabled;
    cTkFixedString<64,char> macName;
    cTkDynamicArray<cTkFixedString<64,char>> maNodeNames;
    cTkVector3 mCentreOfMassLocal;
    cTkVector3 mPivotLocal;
    ePivotAnchorsTo PivotAnchorsTo;
    cTkVector3 mPivotAnchorLocal;
    cTkFixedString<64,char> macPivotAnchorNode;
    float mfApplyGameGravity;
    float mfApplyGameWind;
    float mfAirSpeedFromMovementSpeedScale;
    bool mbPositionalSpringEnabled;
    float mfDampingCriticality;
    float mfNaturalFrequency;
    bool mbSpringPivots;
    bool mbApplySpringInMovingFrame;
    eApplyMotionScaleIn ApplyMotionScaleIn;
    float mfMotionScale_Uniform;
    cTkVector3 mMotionScale;
    eApplyMotionLimitsIn ApplyMotionLimitsIn;
    float mfMotionLimit_MaxDetachmentDistance;
    cTkVector3 mMotionLimitMin;
    cTkVector3 mMotionLimitMax;
    cTkVector3 mMotionLimitBounciness;
    bool mbAngularSpringEnabled;
    float mfInfluenceOfTranslation;
    float mfApplyInfluenceOfTranslationInMovingFrame;
    float mfDistanceWhereRotationMatchesLinear;
    float mfAngularDampingCriticality;
    float mfAngularNaturalFrequency;
    float mfApplyAngularSpringInMovingFrame;
    eApplyAngularMotionScaleIn ApplyAngularMotionScaleIn;
    float mfAngularMotionScale_Uniform;
    cTkVector3 mAngularMotionScale;
    eApplyAngularLimitsIn ApplyAngularLimitsIn;
    cTkVector3 mAngularLimitMinDeg;
    cTkVector3 mAngularLimitMaxDeg;
    cTkVector3 mAngularMotionLimitBounciness;
}
