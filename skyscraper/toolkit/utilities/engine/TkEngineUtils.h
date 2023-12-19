/**
 * @file TkEngineUtils.h
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

#include <toolkit/core/types/TkHandle.h>
#include <toolkit/core/types/TkTypes.h>
#include <toolkit/maths/geometry/TkAABB.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/resources/TkResourceDescriptor.h>
#include <toolkit/simulation/TkSeed.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/string/TkString.h>

SKYSCRAPER_BEGIN

class cEgSceneNodeTemplate;
class cTkAttachment;

enum eMasterModelNodeDistance
{
    Root,
    First,
};

class TkAddNodesHandle
{
  public:
    enum eAddNodesState
    {
        EAddNodesState_None,
        EAddNodesState_Searching,
        EAddNodesState_Adding
    };

    enum eState
    {
        EState_Adding,
        EState_Preparing,
        EState_Complete,
    };

    TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mSceneGraphResource;
    TkHandle mParentNode;
    TkHandle mNode;
    TkHandle mLastAddedNode;
    std::shared_ptr<TkAddNodesHandle> mpAddReferencedResourceHandle;
    uint64_t mu64Timeout;
    cEgSceneNodeTemplate *mpLastAddedTemplate;
    cTkAttachment *mpCurrentAttachment;
    int miCount;
    eAddNodesState meAddNodesState;
    eState meState;
};

class cTkEngineUtils
{
  public:
    static cTkPhysRelMat34 *ComputePhysRelMatFromNode(cTkPhysRelMat34 *result, TkHandle lHandle);
    static void GetNodeChildOBBs(TkHandle lNode, cTkVector<cTkAABB> *lAABBGroupOut, int liNodeType);
    static bool GetNodeOBB(
        TkHandle lNode, cTkAABB *lpAABBOut, int liNodeType, bool lbActiveNodesOnly, bool lbIncludeParentsInActiveCheck);
    static TkHandle *AddNodes(
        TkHandle *result, TkHandle lBaseNode, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lResourceHandle,
        const cTkMatrix34 *lStartMatrix, bool lbRelative);
    static TkHandle *AddNodes(
        TkHandle *result, TkHandle lBaseNode, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lResourceHandle,
        const cTkPhysRelMat34 *lStartMatrix, bool lbRelative);
    static TkHandle *AddNodesNoPrepare(
        TkHandle *result, TkHandle lBaseNode, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lResourceHandle,
        const cTkPhysRelMat34 *lStartMatrix, bool lbRelative);
    static TkAddNodesHandle *AddNodesStep(
        TkAddNodesHandle *result, TkHandle lParent, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lSceneGraphRes,
        const cTkMatrix34 *lTransformMatrix, bool lbRelative, int liMaxNumNodesToAdd);
    static TkHandle *AddNodesStep(TkHandle *result, TkAddNodesHandle *lHandle, int liMaxNumNodesToAdd);
    static std::function<bool(TkHandle)> *FindNode(
        std::function<bool(TkHandle)> *result, TkHandle lNode, uint32_t luNameHash, int liType);
    static std::function<bool(TkHandle)> *FindNode(
        std::function<bool(TkHandle)> *result, TkHandle lNode, const char *lpacName, int liType);
    static TkHandle *FindNodeContainingString(
        TkHandle *result, TkHandle lNode, cTkFixedString<128, char> *lpacName, int liType);
    static TkHandle *GetGroupNode(TkHandle *result, TkHandle lNode);
    static TkHandle *GetMasterModelNode(TkHandle *result, TkHandle lNode, eMasterModelNodeDistance lDistance);
    static bool GetMatricesFromNode(TkHandle lHandle, cTkMatrix34 *lAbsoluteMatrix, cTkMatrix34 *lRelativeMatrix);
    static TkHandle *GetModelNode(TkHandle *result, TkHandle lNode);
    static TkStrongType<int, TkStrongTypeIDs::TkResHandleID> *GetResHandleFromNode(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> *result, TkHandle lNode, cTkResourceDescriptor *lResDesc);
    static cTkSeed *GetSeedFromNode(cTkSeed *result, TkHandle lNode);
    static bool IsNodeImposter(TkHandle lNode);
    static bool ReadModelFileName(TkHandle lModelNode, cTkFixedString<128, char> *lFilenameOut);
    static void RepositionGroupNode(TkHandle lGroupNode, const cTkVector3 *lDesiredPosition);
    static void RequestTexturesAlwaysResident(TkHandle lBaseNode, bool lbValue);
    static void SetNodeActive(TkHandle lHandle, bool lbActive);
    static void SetNodeActiveRecursive(TkHandle lHandle, bool lbActive);
    static void SetNodeMatrixWorld(TkHandle lHandle, const cTkMatrix34 *lMatrix);
    static void SetNodeMatrixWorld(TkHandle lHandle, const cTkPhysRelMat34 *lMatrix);
    static void SetNodeParent(TkHandle lNode, TkHandle lParent, bool lbPreserveTransforms);
    static void SetSceneNetworkId(TkHandle lNode, const char *lId, uint32_t lIndex, bool lbIncludeAttachments);
};

SKYSCRAPER_END