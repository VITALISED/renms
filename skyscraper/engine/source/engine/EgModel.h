#pragma once

#include <skyscraper.h>

#include <engine/source/engine/EgGeometry.h>
#include <engine/source/engine/EgScene.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cEgModelNode : public cEgSceneNode
{
    cTkTypedSmartResHandle<cEgGeometryResource> mpGeometryResource;
    cTkTypedSmartResHandle<cEgGeometryResource> mpBaseGeometryResource;
    float mfCullDist;
    float mfAnimOffset;
    unsigned int muVertBufferIndex;
    float mfFadeValue;
    int miChildMeshType;
    cTkVector<cEgRenderableSceneNode *> mRenderableList;
    std::vector<unsigned short, TkSTLAllocatorShim<unsigned short, 2, -1>> mSkinMatrixInds;
    cEgAnimationController mAnimationController;
    std::vector<
        cCallbackWithPriority<cPreAdditiveCallback>,
        TkSTLAllocatorShim<cCallbackWithPriority<cPreAdditiveCallback>, 8, -1>>
        mPreAdditiveCallbacks;
    std::vector<
        cCallbackWithPriority<cOnPostAnimCallback>,
        TkSTLAllocatorShim<cCallbackWithPriority<cOnPostAnimCallback>, 8, -1>>
        mOnPostAnimCallbacks;
    bool mbNodeListDirty;
    bool mbMorpherUsed;
    bool mbMorpherDirty;
    bool mbHasOldSkinMats;
    bool mbUpdateBoundingFromAnim;
    bool mbAnimCulled;
    std::vector<cTkVector4, TkSTLAllocatorShim<cTkVector4, 16, -1>> mSkinMatrixRows;
    std::vector<cTkVector4, TkSTLAllocatorShim<cTkVector4, 16, -1>> mPrevSkinMatrixRows;
    int miPrevSkinRowsFrame;
    std::vector<cEgJointNode *, TkSTLAllocatorShim<cEgJointNode *, 8, -1>> mJointList;
    std::vector<int, TkSTLAllocatorShim<int, 4, -1>> maJointIndex;
    std::vector<int, TkSTLAllocatorShim<int, 4, -1>> maJointParentIndex;
    int miMaxJointIndex;
    unsigned __int64 muPreAsyncUpdateFrame;
    unsigned __int64 muAsyncUpdateFrame;
    unsigned __int64 muPostAsyncUpdateFrame;
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