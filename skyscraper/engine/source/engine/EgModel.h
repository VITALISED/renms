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
  public:
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
    cTkVector<cTkVector4, TkSTLAllocatorShim<cTkVector4, 16, -1>> mSkinMatrixRows;
    cTkVector<cTkVector4, TkSTLAllocatorShim<cTkVector4, 16, -1>> mPrevSkinMatrixRows;
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