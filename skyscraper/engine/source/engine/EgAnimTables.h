/**
 * @file EgAnimTables.h
 * @author VITALISED & Contributors
 * @since 2024-01-22
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

#include <engine/source/engine/EgAnimation.h>
#include <engine/source/engine/EgRenderQueue.h>
#include <engine/source/engine/EgScene.h>

SKYSCRAPER_BEGIN

class cEgMeshNodeTemplate : public cEgSceneNodeTemplate
{
  public:
    virtual void SetName(const char *);
    virtual void SetDescriptor(const cTkSharedPtr<cTkResourceDescriptor const> *);
    virtual void GatherMaterials(cTkVector<TkStrongType<int, TkStrongTypeIDs::TkResHandleID>> *);
    virtual cTkAABB *GetBoundingBox(
        cTkAABB *result, const cTkResourceDescriptor *, cEgGeometryResource *, const cTkMatrix34 *, bool, bool);
    virtual bool IsGeometryStreamedIn(cEgGeometryResource *, cEgResource *);

    cTkTypedSmartResHandle<cEgMaterialResource> mMatRes;
    uint32_t muBatchStart;
    uint32_t muBatchCount;
    uint32_t muBatchStartPhysics;
    uint32_t muVertRStart;
    uint32_t muVertREnd;
    uint32_t muVertRStartPhysics;
    uint32_t muVertREndPhysics;
    uint32_t muBvVertStart;
    uint32_t muBvVertEnd;
    uint32_t muFirstSkinMat;
    uint32_t muLastSkinMat;
    uint32_t muLodLevel;
    uint64_t mu64Hash;
    cTkAABB mAABB;
};

class cEgMeshNode : public cEgRenderableSceneNode, public IAnimatableNode
{
  public:
    virtual ~cEgMeshNode();
    virtual int GetParameterInt(int);
    virtual void SetParameterInt(int, int);
    virtual float GetParameterFloat(int, int);
    virtual void SetParameterFloat(int, int, float);
    virtual void GetVisibleBBox(cEgBoundingBox *);
    virtual bool CanAttach(cEgSceneNode *);
    virtual bool CheckIntersection(const cTkVector3 *, const cTkVector3 *, cTkVector3 *);
    virtual void OnAttach(cEgSceneNode *);
    virtual const char *GetANName();
    virtual uint32_t GetANNameHash();
    virtual IAnimatableNode *GetANParent();

    cEgMeshNodeTemplate *Parse(
        cEgMeshNodeTemplate *lpTemplate, const cTkDynamicArray<cTkSceneNodeAttributeData> &lAttributes,
        cTkResourceDescriptor *lpResourceDescriptor, int lxResourceFlags);

    static void EnqueueFunc(
        cEgRenderQueueInfo *queueInfo, cEgRenderQueueEntry *queueEntries, cEgRenderableSceneNode **queueNodes,
        const cEgFrustum &frustum, int shadowSplitIndex, int liNumNodes);
    static void FactoryFunc(const cEgSceneNodeTemplate &lNodeTemplate, cTkSlotAlloc *lpSlotAlloc);
    static cEgMeshNodeTemplate *ParsingFunc(
        const cTkDynamicArray<cTkSceneNodeAttributeData> &lAttributes, cTkResourceDescriptor *lpResourceDescriptor,
        int lxResourceFlags);

    uint64_t mu64Hash;
    uint32_t muBatchStart;
    uint32_t muBatchCount;
    uint32_t muBatchStartPhysics;
    uint32_t muVertRStart;
    uint32_t muVertREnd;
    uint32_t muVertRStartPhysics;
    uint32_t muVertREndPhysics;
    uint32_t muBvVertStart;
    uint32_t muBvVertEnd;
    uint32_t muLodLevel;
    uint32_t muFirstSkinMat;
    uint32_t muLastSkinMat;
    float mfLodFade;
    cTkVector4 mUserData;
    cEgModelNode *mpMasterParentModel;
    int miGeometryBufferIndex;
};

SKYSCRAPER_END