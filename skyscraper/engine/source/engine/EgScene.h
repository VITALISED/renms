/**
 * @file EgScene.h
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
#include <engine/source/engine/EgMaterial.h>
#include <engine/source/engine/EgScene.h>
#include <toolkit/core/types/TkHandle.h>
#include <toolkit/maths/geometry/TkAABB.h>
#include <toolkit/resources/TkResource.h>
#include <toolkit/resources/TkResourceDescriptor.h>
#include <toolkit/system/memory/TkRefCounted.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/engine/TkEngineUtils.h>

#include <toolkit/attachments/tkattachmentdata.meta.h>
#include <toolkit/scene/tkscenenodeattributedata.meta.h>

SKYSCRAPER_BEGIN

struct RenderingOrder
{
    enum List
    {
        None,
        FrontToBack,
        BackToFront,
        StateChanges,
        Mesh,
        Custom,
        NumRenderingOrders,
    };
};

class cEgNodeAttachment
{
  public:
    virtual ~cEgNodeAttachment();
    virtual void OnUpdate();

    void AttachToNode(TkHandle lNode);
    cEgNodeAttachment *GetFromNode(TkHandle lNode);

    TkHandle mNode;
};

class cEgSceneNode
{
  public:
    virtual ~cEgSceneNode();
    virtual void ParseRefAttrib(cTkSceneNodeAttributeData *);
    virtual int GetParameterInt(int);
    virtual void SetParameterInt(int, int);
    virtual float GetParameterFloat(int, int);
    virtual void SetParameterFloat(int, int, float);
    virtual cTkVector3 *GetParameterVec3(cTkVector3 *result, int, int);
    virtual void SetParameterVec3(int, int, const cTkVector3 *);
    virtual const char *GetParameterStr(int);
    virtual void SetParameterStr(int, const char *);
    virtual void GetVisibleBBox(cEgBoundingBox *);
    virtual unsigned int CalculateLodLevel(const cTkVector3 *);
    virtual bool CanAttach(cEgSceneNode *);
    virtual bool CheckIntersection(const cTkVector3 *, const cTkVector3 *, cTkVector3 *);
    virtual int GetClassOverride();
    virtual void Update();
    virtual bool PreAsyncUpdate();
    virtual void AsyncUpdate();
    virtual void PostAsyncUpdate();
    virtual void OnAttach(cEgSceneNode *);
    virtual void OnDetach(cEgSceneNode *);
    virtual void PreTransferRenderData();
    virtual void OnDetachInstanceAware(cEgSceneNode *);

    cTkMatrix34 &ComputePrevTransformInOffsetSpace(const cTkVector3 &lvOffset);
    cTkMatrix34 &ComputeTransformInOffsetSpace(const cTkVector3 &lvOffset);
    void SetHasAsyncUpdate(bool lbUpdates);
    void SetHasLods(bool lbHasLods);
    void SetRenderable(bool lbRenderable);
    void SetTransform(const cTkMatrix34 &lMatrix);

    TkHandle mLookupHandle;
    unsigned int muNameHash;
    cTkSmartResHandle mResHandle;
    unsigned int muNetworkId;
    cTkSharedPtr<std::string> msName;
    cTkSharedPtr<cTkResourceDescriptor const> mpAltId;
    cEgNodeAttachment *mpNodeAttachment;
    cTkSlotAlloc *mpAllocator;
    int miIsMaster;
};

class cEgModelNode;

class cEgRenderableSceneNode : public cEgSceneNode
{
  public:
    virtual ~cEgRenderableSceneNode();
    virtual void OnAttach(cEgSceneNode *);
    virtual void OnDetach(cEgSceneNode *);

    void RecalculateRenderID();

    cTkTypedSmartResHandle<cEgMaterialResource> mpMaterialResource;
    cEgModelNode *mpParentModel;
    int miRenderLayer;
};

class cEgSceneNodeTemplate
{
  public:
    int miType;
    unsigned int muNameHash;
    cTkSharedPtr<std::string> msName;
    cTkSharedPtr<cTkResourceDescriptor const> mpDescriptor;
    cTkVector3 mTranslation;
    cTkVector3 mRotation;
    cTkVector3 mScale;
    cTkAttachmentData *mpAttachment;
    cEgSceneNode *mpParent;
    TkHandle mHandle;
    cTkVector<cEgSceneNodeTemplate *> mChildren;

    virtual ~cEgSceneNodeTemplate();
    virtual void SetName(const char *);
    virtual void GatherMaterials(cTkVector<TkStrongType<int, TkStrongTypeIDs::TkResHandleID>> *);
    virtual void GatherData(cTkVector<cTkAttachmentData *> *);
    virtual cTkAABB *GetBoundingBox(
        cTkAABB *result, const cTkResourceDescriptor *, cEgGeometryResource *, const cTkMatrix34 *, bool, bool);
    virtual bool IsGeometryStreamedIn(cEgGeometryResource *, cEgResource *);
    virtual bool IsLoaded();
};

SKYSCRAPER_END