/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <skyscraper.h>

#include <atlas/WinHttpTask.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>
#include <toolkit/maths/numeric/TkAngles.h>
#include <toolkit/maths/numeric/TkQuaternion.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/engine/TkEngineUtils.h>

SKYSCRAPER_BEGIN

typedef WinHttpTask::State::Enum eIkConstraintType;

struct AnimTransform
{
    cTkVector3 mNodeScale;
    cTkQuaternion mNodeRotationQuat;
    cTkVector3 mNodeTranslation;
    bool mbNodeUpdated;
};

class cTkJacobianRow
{
    int miStateSize;
    int miStateSizeAlignedUp;
    float mfValue;
    float *mafDerivs;
};

class cTkIKFullBody;

class cTkIKConstraint
{
    float mfStrength;
    bool mbEnable;
    eIkConstraintType mType;

    virtual void OnAttach(cTkIKFullBody *);
    virtual void OnDetach(cTkIKFullBody *);
    virtual void PreAdditive(
        cTkIKFullBody *, const cTkMatrix34 *, const cTkMatrix34 *, const cTkEulerVector *, const cTkEulerVector *);
    virtual void PostAnim(cTkIKFullBody *, cTkMatrix34 *, AnimTransform *);
    virtual void PreSolve(
        cTkIKFullBody *, const cTkMatrix34 *, const cTkMatrix34 *, const cTkEulerVector *, const cTkEulerVector *);
    virtual void GetNumRows(int *, int *);
    virtual void BuildRows(
        cTkJacobianRow *, cTkJacobianRow *, const cTkIKFullBody *, const cTkMatrix34 *, const cTkEulerVector *);
    virtual void PostSolve(cTkIKFullBody *, const cTkMatrix34 *, cTkMatrix34 *);
};

class cTkIKJointXZPushConstraint : public cTkIKConstraint
{
    cTkVector3 mvDesiredPos;
    cTkEulerVector mvDesiredRot;
    TkHandle muNode;
    int mBoneIndex;
    float mfXChange;
    float mfZChange;
    float mfRotHoldStrength;
};

class cTkIKJointHeightConstraint : public cTkIKConstraint
{
    cTkVector3 mvDesiredPos;
    cTkVector3 mvBoneOffset;
    cTkEulerVector mvDesiredRot;
    TkHandle muNode;
    int mBoneIndex[2];
    float mfHeightChange;
    float mfHoldRotStrength;
    float mfAngleChange;
    float mfAngleChangeZ;
    int mJointIndex;
};

class cTkIKCenterOfGravityConstraint : public cTkIKConstraint
{
    cTkVector3 mvDesiredPos;
    cTkVector3 mvPosChange;
};

class cTkIKRotYModifyConstraint : public cTkIKConstraint
{
    float mfDesiredRot;
    TkHandle muNode;
    int mBoneIndex;
    float mfRotChange;
};

class cGcPistonConstraint : cTkIKConstraint
{
    TkHandle muJoint1;
    int miJoint1Index;
    TkHandle muJoint2;
    int miJoint2Index;
    cTkMatrix34 mJoint1ModelSpaceMat;
    cTkMatrix34 mJoint2ModelSpaceMat;
};

class cPreAdditiveCallback
{
    virtual void PreAdditive(cTkMatrix34 *, AnimTransform *, int);
};

template <typename T>
class cTkPreAdditiveCallbackForwarder : public cPreAdditiveCallback
{
    T *mForwardedTo;
};

class cOnPostAnimCallback
{
    virtual void OnPostAnim(cTkMatrix34 *, AnimTransform *, int, const cTkPhysRelMat34 *);
};

template <typename T>
class cTkOnPostAnimCallbackForwarder : public cOnPostAnimCallback
{
    T *mForwardedTo;
};

class cTkIKFullBody
{
  public:
    enum ActiveAxes
    {
        EActiveIKAxes_XYZ,
        EActiveIKAxes_X,
        EActiveIKAxes_Y,
        EActiveIKAxes_Z,
        EActiveIKAxes_XY,
        EActiveIKAxes_XZ,
        EActiveIKAxes_YZ,
        EActiveIKAxes_Nil,
    };

    struct BoneInfo
    {
        cTkMatrix34 mInvBind;
        cTkMatrix34 mInvRelBind;
        cTkMatrix34 mBind;
        cTkMatrix34 mPostJointAdjustBind;
        AnimTransform mBindXform;
        AnimTransform mPreJointAdjustPose;
        cTkEulerVector mvEulerVec;
        cTkEulerVector mvRelBindEulerVec;
        cTkVector3 mvAabbMin;
        cTkVector3 mvAabbMax;
        float mfChildrenMass;
        int miParentBoneIndex[2];
        int miJointIndex;
        int mLimbIndex;
        TkHandle muNode;
        int mAxes;
        int mPositionInState;
        int miNumStateVals;
        float mOriginalMass;
        float mMass;
    };

    cTkVector<cTkIKFullBody::BoneInfo> maBones;
    cTkPreAdditiveCallbackForwarder<cTkIKFullBody> mPreAdditiveCallbackForwarder;
    cTkOnPostAnimCallbackForwarder<cTkIKFullBody> mOnPostAnimCallbackForwarder;
    cTkVector3 mExternalRealignmentVector;
    cTkVector3 mInternalRealignmentVector;
    float mfIterations;
    float mfOmega;
    float mfOmegaDropOff;
    float mfJointLimitDegrees;
    float mfJointLimitHardness;
    float mfBodyMassWeight;
    float mfMovementDamp;
    float mfScaler;
    int miMaxJointInd;
    int miStateSize;
    cTkVector<cTkIKConstraint *> maConstraints;
    int miHighlightedBone;
    int miSelectedBone;
    int miRealignmentBone;
    bool mbRealignmentEnabled;
    bool mbVerticalRealignmentEnabled;
    bool mbEnable;
    bool mbLockedRoot;
    int mIkVersion;
    bool mSelectedForDebugDraw;
};

SKYSCRAPER_END