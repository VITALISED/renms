/**
 * @file EgModel.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
 *
 * Copyright (C) 2023  VITALISED & Contributors
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

#include <engine/source/engine/EgAnimTables.h>
#include <engine/source/engine/EgAnimation.h>
#include <engine/source/engine/EgGeometry.h>
#include <engine/source/engine/EgScene.h>
#include <toolkit/system/timer/TkTimer.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cEgModelNode;

template <typename T>
class cCallbackWithPriority
{
    T *mCallback;
    int mPriority;
};

class cEgLodNodes
{
  public:
    void AddNode(int liNodIndex, cEgRenderableSceneNode *lpNode);

    static bool CheckMeshesMatch(
        cEgSceneNode *lpNode1, const cTkFixedString<256, char> &lsNode1Name, cEgSceneNode *lpNode2,
        const cTkFixedString<256, char> &lsNode2Name);
    static void GetGenericMeshName(cEgSceneNode *lpNode, cTkFixedString<256, char> &lsOutName);

    int miNumLods;
    int miNumMeshes;
    cTkStackVector<std::array<TkHandle, 5>, 2> mapLodNodes;
};

class cEgJointNode : public cEgSceneNode, public IAnimatableNode
{
  public:
    virtual int GetParameterInt(int);
    virtual void OnAttach(cEgSceneNode *);
    virtual void OnDetach(cEgSceneNode *);
    virtual const char *GetANName();
    virtual uint32_t GetANNameHash();
    virtual int GetJointIndex();

    static cEgJointNode *FactoryFunc(const cEgSceneNodeTemplate &lNodeTemplate, cTkSlotAlloc *lpSlotAlloc);

    cEgModelNode *mpParentModel;
    cTkMatrix34 mBaseMatrix;
    unsigned int muJointIndex;
};

class cEgModelNode : public cEgSceneNode
{
  public:
    virtual ~cEgModelNode();
    virtual void ParseRefAttrib(cTkSceneNodeAttributeData *);
    virtual int GetParameterInt(int);
    virtual void SetParameterInt(int, int);
    virtual float GetParameterFloat(int, int);
    virtual void SetParameterFloat(int, int, float);
    virtual cTkVector3 *GetParameterVec3(cTkVector3 *result, int, int);
    virtual unsigned int CalculateLodLevel(const cTkVector3 *);
    virtual bool PreAsyncUpdate();
    virtual void AsyncUpdate();
    virtual void PostAsyncUpdate();
    virtual void OnAttach(cEgSceneNode *);
    virtual void RecreateNodeList();
    virtual void UpdateLocalMeshAABBs();
    virtual int GetLodMeshType();

    // this could be uint16_t ret
    uint32_t *AddSkinMatsToBuffer(uint32_t luFirstGeoSkinMat, uint32_t luLastGeoSkinMat);
    void Animate();
    void BuildMatFromAnimData(const AnimTransform *lMatVec);
    void CacheSkeleton();
    // not sure what the enum is for this, seems to be 0-4
    int CalculateLodLevel(const cTkVector3 &lViewPoint);
    void FinishAnimate();
    bool GetLocatorForAnim(
        cEgAnimationResource *lpAnimationResource, const TkID<128> &lLocId, float lfPhase, bool lbMirrored,
        cTkVector3 &lTranslationOut, cTkQuaternion &lRotationOut);
    cTkVector3 &GetSkinnedVert(uint32_t liVert, cTkVector3 *lpNormal, cTkVector3 *lpTangent, cTkVector2 *);
    void OnSubNodeAttached(cEgSceneNode *lpNode);
    void ParseRefAttrib(cTkSceneNodeAttributeData &lAttrib);
    void PrepAnimate();
    void RecalculateLocalMeshAABB(cEgGeometryAABBCache *lpAABBCache, cEgMeshNode &lMeshNode, int &liMeshIndexHint);
    void RecreateNodeListRec(cEgSceneNode *lpNode, bool lbFirstCall, int liDepth);
    void SetAnimJointsLOD(int liLOD, cTkFixedString<64, char> *lNodeNames, int liNumNodes);
    bool SwitchToEditedGeometry();
    bool UpdateGeometry();
    void UpdateLod(const cTkVector3 &lCameraPosition, float lfFadeTime);
    void UpdateLod_HasLods(float lfFadeTime);
    void UpdateLod_HasLodsImmediate();

    static cEgSceneNodeTemplate *ParsingFunc(
        const cTkDynamicArray<cTkSceneNodeAttributeData> &lAttributes, cTkResourceDescriptor *lpResourceDescriptor,
        int lxResourceFlags);
    static cEgModelNode *FactoryFunc(const cEgSceneNodeTemplate &lNodeTemplate, cTkSlotAlloc *lpSlotAlloc);

    struct AnimationWorkBuffer
    {
        cTkMatrix34 *maPose;
        cTkMatrix34 *maRelativeModelMatrix;
        cEgBoundingBox mLocalAabb;
    };

    cTkTypedSmartResHandle<cEgGeometryResource> mpGeometryResource;
    cTkTypedSmartResHandle<cEgGeometryResource> mpBaseGeometryResource;
    float mfCullDist;
    float mfAnimOffset;
    unsigned int muVertBufferIndex;
    float mfFadeValue;
    int miChildMeshType;
    cTkVector<cEgRenderableSceneNode *> mRenderableList;
    cTkVector<unsigned short> mSkinMatrixInds;
    cEgAnimationController mAnimationController;
    cTkVector<cCallbackWithPriority<cPreAdditiveCallback>> mPreAdditiveCallbacks;
    cTkVector<cCallbackWithPriority<cOnPostAnimCallback>> mOnPostAnimCallbacks;
    bool mbNodeListDirty;
    bool mbMorpherUsed;
    bool mbMorpherDirty;
    bool mbHasOldSkinMats;
    bool mbUpdateBoundingFromAnim;
    bool mbAnimCulled;
    cTkVector<cTkVector4> mSkinMatrixRows;
    cTkVector<cTkVector4> mPrevSkinMatrixRows;
    int miPrevSkinRowsFrame;
    cTkVector<cEgJointNode *> mJointList;
    cTkVector<int> maJointIndex;
    cTkVector<int> maJointParentIndex;
    int miMaxJointIndex;
    uint64_t muPreAsyncUpdateFrame;
    uint64_t muAsyncUpdateFrame;
    uint64_t muPostAsyncUpdateFrame;
    float mafLodDistances[5];
    float mafAdjustedLodDistances[5];
    float mafAdjustedLodDistSqr[5];
    cTkTimerTemplate<0> mLodFadeTimer;
    int miCurrentLod;
    int miNextLod;
    const int miMaxTemplateNumLods;
    int miMaxChildTemplateNumLods;
    cEgLodNodes mLodNodes;
    bool mbCreatedNodeList;
    cEgModelNode::AnimationWorkBuffer mAnimWorkBuf;
};

SKYSCRAPER_END