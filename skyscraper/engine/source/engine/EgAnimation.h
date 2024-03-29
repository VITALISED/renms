/**
 * @file EgAnimation.h
 * @author VITALISED & Contributors
 * @since 2024-01-01
 *
 * Copyright (C) 2024  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <skyscraper.h>

#include <engine/source/engine/EgModel.h>
#include <engine/source/engine/EgResource.h>
#include <toolkit/animation/engine/TkNodeAnimationControllerEngine.h>
#include <toolkit/animation/utils/TkIKSolver.h>
#include <toolkit/utilities/containers/TkFlatMap.h>
#include <toolkit/utilities/containers/TkStackContainer.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <toolkit/scene/animation/tkanimmetadata.meta.h>
#include <toolkit/scene/animation/tkanimnodedata.meta.h>

SKYSCRAPER_BEGIN

class cEgModelNode;

class IAnimatableNode
{
  public:
    virtual ~IAnimatableNode();
    virtual const char *GetANName();
    virtual unsigned int GetANNameHash();
    virtual bool IsJoint();
    virtual int GetJointIndex();
    virtual int GetLOD();
    virtual void SetLOD(int);
    virtual IAnimatableNode *GetANParent();
    virtual cEgModelNode *GetParentModel();
    int miNodeIndex;
    int miNodeLOD;
};

struct Frame
{
    cTkQuaternion mQuatRotation;
    cTkVector3 mTranslation;
    cTkVector3 mScale;
    cTkMatrix44 mBakedTransformMatrix;
};

struct AnimResEntity
{
    std::string msName;
    cTkMatrix44 mFirstFrameInvTrans;
    cTkVector<Frame> mFrames;
};

class cEgAnimationResource : public cEgResource
{
  public:
    unsigned int muNumFrames;
    cTkVector<AnimResEntity> mEntities;
    cTkAnimMetadata *mpData;
    cTkFlatMap<unsigned int, int, cTkKeyPairCompareLess<unsigned int, int>> mEntityLookup;
    int miMaxSize;
};

class cEgAnimationController
{
  public:
    struct AnimMapping;

    void ResizeNodeList();
    void RegisterNode(IAnimatableNode *lpNode);
    cEgAnimationController::AnimMapping *CreateAnimMapping(
        const TkID<128> &lName, cEgAnimationResource *lpAnim, const cTkStackVector<uint32_t, 1> &lStartNodeHashes);
    void MapAnimationResource(
        uint32_t luNode, cEgAnimationResource *lpAnimResource, const cTkStackVector<uint32_t, 1> &lStartNodeHashes,
        cEgAnimationController::AnimMapping *lpMap);
    bool SetWorldPoseMatrix(int liJointIndex, const cTkMatrix34 &lMatrix);
    void RRunPreAdditiveCallback(
        AnimTransform *laXformArray, const int *laJointIndex, const int *laJointParentIndex, int liNumJoints,
        cTkVector<cCallbackWithPriority<cPreAdditiveCallback>> &preAdditiveCallbacks);
    void WriteBindPose(
        AnimTransform *laXformArray, cEgGeometryResource *lpGeoRes, cTkVector<bool> &lbIgnoreJoints,
        const int *laNodeToJoint, int liNumNodes);
    void MirrorPose(
        AnimTransform *laCurStage, cEgGeometryResource *lpGeoRes, IAnimatableNode **lNodeList,
        cTkVector<bool> &lbIgnoreJoints, const int *laNodeToJoint, const int *laJointToNode, int liNumNodes);
    void ExtractZeroFrame(
        AnimTransform *laXformArray, const cEgAnimationController &lMapping, cTkVector<bool> &lbIgnoreJoints,
        const int *laNodeToJoint, int liNumNodes);
    // Learnt a new word today
    void Subtract(
        AnimTransform *laSubtractFrom, AnimTransform *laSubtrahend, cTkVector<bool> &lbIgnoreJoints,
        const int *laNodeToJoint, int liNumNodes);
    void Add(
        AnimTransform *laCurStage, AnimTransform *laXformArray, float lfWeight, cEgGeometryResource *lpGeoRes,
        cTkVector<bool> &lbIgnoreJoints, const int *laNodeToJoint, int liNumNodes);
    void NlerpAdd(
        AnimTransform *laCurStage, AnimTransform *laXformArray, float lfWeight, cEgGeometryResource *lpGeoRes,
        cTkVector<bool> &lbIgnoreJoints, const int *laNodeToJoint, int liNumNodes);
    void NlerpComplete(
        AnimTransform *laCurStage, float lfWeight, cEgGeometryResource *lpGeoRes, cTkVector<bool> &lbIgnoreJoints,
        const int *laNodeToJoint, int liNumNodes);
    void NlerpMultiplt(
        AnimTransform *laCurStage, float lfWeight, cEgGeometryResource *lpGeoRes, cTkVector<bool> &lbIgnoreJoints,
        const int *laNodeToJoint, int liNumNodes);
    void Multiply(
        AnimTransform *laCurStage, AnimTransform *laXformArray, float lfWeight, cEgGeometryResource *lpGeoRes,
        cTkVector<bool> &lbIgnoreJoints, const int *laNodeToJoint, int liNumNodes);
    void Blend(
        AnimTransform *laCurStage, AnimTransform *laXformArray, float lfWeight, cEgGeometryResource *lpGeoRes,
        cTkVector<bool> &lbIgnoreJoints, const int *laNodeToJoint, int liNumNodes);
    void EvalCommandListInternal(
        AnimTransform *laxFormArray_, const int *laNodeToJoint, const int *laJointToNode, const int *laJointIndex,
        const int *laJointParentIndex, cTkVector<bool> &lbIgnoreJoints, int liNumNodes, int liMaxJointIndex,
        cEgGeometryResource *lpGeoRes, cTkVector<cCallbackWithPriority<cPreAdditiveCallback>> &preAdditiveCallback);
    void BuildSkinningMatrices(
        cEgModelNode *lpModel, const cTkMatrix34 &lModelMat, int *laJointIndex, int *laJointParentIndex,
        cEgGeometryResource *lpGeometryResource, cTkMatrix34 *laPose, cTkMatrix34 *laRelativeModelMatrix,
        cTkMatrix34 *laSkinningMats, int64_t liNumJoints);
    bool AddAnimToAdditivePose(
        cEgAnimationResource *lpAnimResource, float lfTIme, float lfWeight, TkID<128> *, float, float);

    struct JointLODGroup
    {
        int miLOD;
        cTkVector<unsigned int> maNameHashes;
    };

    struct AnimMapping
    {
        TkID<128> mName;
        cTkTypedSmartResHandle<cEgAnimationResource> mpAnim;
        cTkVector<cTkAnimNodeData *> mNodeMappings;
        cTkStackVector<unsigned int, 1> mStartNodeHashes;
    };

    cTkStackVector<cTkAnimCommand, 16> mCommandList;
    cTkVector<IAnimatableNode *> mNodeList;
    cTkVector<cEgAnimationController::AnimMapping> mAnimMappings;
    cTkVector<AnimTransform> mAdditivePose;
    cTkVector<int> maNodeToJoint;
    cTkVector<int> maJointToNode;
    cTkVector<bool> mabIgnoreAnimation;
    robin_hood::detail::Table<true, 80, int, void, robin_hood::hash<int, void>, std::equal_to<int>>
        mIgnoreAnimationResetList;
    cTkVector<cEgAnimationController::JointLODGroup> mJointLODs;
    cTkVector<cTkMatrix34> maWorldPose;
    cTkVector<bool> mabWorldPoseActive;
    cTkVector3 mvWorldPoseOffset;
    int miLOD;
    bool mbDirty;
};

SKYSCRAPER_END