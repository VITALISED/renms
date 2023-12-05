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