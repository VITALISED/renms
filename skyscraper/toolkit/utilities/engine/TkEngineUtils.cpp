/**
 * @file TkEngineUtils.cpp
 * @author VITALISED & Contributors
 * @since 2023-12-19
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

#include <toolkit/utilities/engine/TkEngineUtils.h>

SKYSCRAPER_BEGIN

cTkPhysRelMat34 *cTkEngineUtils::ComputePhysRelMatFromNode(cTkPhysRelMat34 *result, TkHandle lHandle)
{
    typedef cTkPhysRelMat34 *(*fn_type)(cTkPhysRelMat34 *result, TkHandle lHandle);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(
        renms_sdk::SignatureScan("40 53 48 83 EC ? 0F 28 05 ? ? ? ? 4C 8D 44 24 30")))(result, lHandle);
}

void cTkEngineUtils::GetNodeChildOBBs(TkHandle lNode, cTkVector<cTkAABB> *lAABBGroupOut, int liNodeType)
{
    typedef void (*fn_type)(TkHandle lNode, cTkVector<cTkAABB> *lAABBGroupOut, int liNodeType);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(renms_sdk::SignatureScan(
        "F7 C1 ? ? ? ? 0F 86 ? ? ? ? 4C 8B DC 49 89 5B 10 49 89 7B 18")))(lNode, lAABBGroupOut, liNodeType);
}
bool cTkEngineUtils::GetNodeOBB(
    TkHandle lNode, cTkAABB *lpAABBOut, int liNodeType, bool lbActiveNodesOnly, bool lbIncludeParentsInActiveCheck)
{
    typedef bool (*fn_type)(
        TkHandle lNode, cTkAABB *lpAABBOut, int liNodeType, bool lbActiveNodesOnly, bool lbIncludeParentsInActiveCheck);

    // i hate the lack of sigmaker
    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(renms_sdk::SignatureScan(
        "48 8B C4 48 89 58 08 48 89 70 10 48 89 78 18 44 88 48 20 55 48 8D 6C 24 80 48 81 EC ? ? ? ? 0F 28 05 ? ? ? ? "
        "48 8B FA 0F 29 70 E8 48 8D 54 24 20 0F 29 78 D8 41 8B F0 44 0F 29 40 C8 8B D9 44 0F 29 48 B8 44 0F 29 50 A8 "
        "44 0F 29 58 98 44 0F 29 60 88 44 0F 29 A8 78 FF FF FF 0F 29 44 24 20 0F 29 44 24 30 0F 29 44 24 40 0F 29 44 "
        "24 50 E8 ? ? ? ? 44 0F 28 4C 24 30 44 0F 28 44 24 40 41 0F 28 E1 44 0F 28 54 24 20 41 0F 28 C0 F3 44 0F 10 2D "
        "? ? ? ? 41 0F 28 C9 F3 44 0F 10 25 ? ? ? ? 41 0F 28 D2 41 0F C6 C0 ? 41 0F 28 DA 41 0F C6 C9 ? 41 0F C6 DA ? "
        "41 0F C6 D2 ? 41 0F C6 E1 ? F3 0F 59 E0 41 0F 28 C0 41 0F C6 C0 ? F3 0F 59 C8 41 0F 28 C1 41 0F C6 C1 ? F3 0F "
        "59 D0 41 0F 28 C1 41 0F C6 C1 ? F3 0F 5C E1 41 0F 28 CA 41 0F C6 CA ? F3 0F 59 C8 41 0F 28 C0 41 0F C6 C0 ? "
        "44 0F 28 DC F3 0F 59 D8 41 0F 28 C0 F3 0F 5C D1 41 0F C6 C0 ? 41 0F 28 CA 41 0F C6 CA ? F3 0F 59 C8 41 0F 14 "
        "D4 F3 0F 5C D9 41 0F 28 CA F3 0F 59 CC 41 0F 57 DD 44 0F 14 DB 41 0F 28 D9 44 0F 16 DA 41 0F 28 D0 41 0F 28 "
        "C3 41 0F C6 C3 ? F3 0F 59 D8 41 0F 28 C3 41 0F C6 C3 ? F3 0F 59 D0 F3 0F 10 05 ? ? ? ? F3 0F 58 D9 F3 0F 58 "
        "DA 0F 2F C3 72 ? 0F 2F 1D ? ? ? ? 72 ? 41 0F 28 E4 EB ? 41 0F 28 E4 F3 0F 5E E3 0F 28 D4 0F 28 FC 41 0F 14 D4 "
        "41 0F 28 D9 0F 14 FC 41 0F 28 EA 0F 16 FA 41 0F 28 E2 41 0F 28 D1 44 0F 59 DF")))(
        lNode, lpAABBOut, liNodeType, lbActiveNodesOnly, lbIncludeParentsInActiveCheck);
}

TkHandle *cTkEngineUtils::AddNodes(
    TkHandle *result, TkHandle lBaseNode, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lResourceHandle,
    const cTkMatrix34 *lStartMatrix, bool lbRelative)
{
    typedef TkHandle *(*fn_type)(
        TkHandle *result, TkHandle lBaseNode, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lResourceHandle,
        const cTkMatrix34 *lStartMatrix, bool lbRelative);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(renms_sdk::SignatureScan(
        "48 8B C4 48 89 58 08 48 89 70 10 48 89 78 18 41 56 48 81 EC ? ? ? ? 0F 29 70 E8 49 8B F1")))(
        result, lBaseNode, lResourceHandle, lStartMatrix, lbRelative);
}

TkHandle *cTkEngineUtils::AddNodes(
    TkHandle *result, TkHandle lBaseNode, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lResourceHandle,
    const cTkPhysRelMat34 *lStartMatrix, bool lbRelative)
{
    typedef TkHandle *(*fn_type)(
        TkHandle *result, TkHandle lBaseNode, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lResourceHandle,
        const cTkPhysRelMat34 *lStartMatrix, bool lbRelative);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(renms_sdk::SignatureScan(
        "48 89 5C 24 08 48 89 74 24 10 57 48 83 EC ? 49 8B F1 8B DA 48 8B F9 E8 ? ? ? ? 80 BC 24 90 00 00 00 ? 8B 0F "
        "74 ? 0F 10 06 8B C1 0F 10 56 30 25 ? ? ? ? 0F 10 4E 10 0F 29 44 24 20 0F 10 46 20 0F 29 4C 24 30 0F 29 44 24 "
        "40 0F 58 56 40 66 0F 7F 54 24 50 F7 C1 ? ? ? ? 76 ? 3D ? ? ? ? 74 ? 85 C0 74 ? 48 8D 54 24 20 E8 ? ? ? ? EB ? "
        "48 8B D6 E8 ? ? ? ? 8B D3 48 8D 8C 24 90 00 00 00 E8 ? ? ? ? 8B 84 24 90 00 00 00 A9 ? ? ? ? 76 ? 25 ? ? ? ? "
        "3D ? ? ? ? 74 ? 65 48 8B 04 25 ? ? ? ? 8B 0D ? ? ? ? 8B 1F BA ? ? ? ? C6 84 24 90 00 00 00 ? 48 8B 0C C8 8B "
        "04 0A 39 05 ? ? ? ? 7F ? 48 8D 94 24 90 00 00 00 8B CB E8 ? ? ? ? 8B 0F")))(
        result, lBaseNode, lResourceHandle, lStartMatrix, lbRelative);
}

TkHandle *cTkEngineUtils::AddNodesNoPrepare(
    TkHandle *result, TkHandle lBaseNode, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lResourceHandle,
    const cTkPhysRelMat34 *lStartMatrix, bool lbRelative)
{
    typedef TkHandle *(*fn_type)(
        TkHandle *result, TkHandle lBaseNode, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lResourceHandle,
        const cTkPhysRelMat34 *lStartMatrix, bool lbRelative);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(renms_sdk::SignatureScan(
        "48 89 5C 24 08 48 89 74 24 10 57 48 83 EC ? 49 8B F1 8B DA 48 8B F9 E8 ? ? ? ? 80 BC 24 90 00 00 00 ? 8B 0F "
        "74 ? 0F 10 06 8B C1 0F 10 56 30 25 ? ? ? ? 0F 10 4E 10 0F 29 44 24 20 0F 10 46 20 0F 29 4C 24 30 0F 29 44 24 "
        "40 0F 58 56 40 66 0F 7F 54 24 50 F7 C1 ? ? ? ? 76 ? 3D ? ? ? ? 74 ? 85 C0 74 ? 48 8D 54 24 20 E8 ? ? ? ? EB ? "
        "48 8B D6 E8 ? ? ? ? 8B D3 48 8D 8C 24 90 00 00 00 E8 ? ? ? ? 8B 84 24 90 00 00 00 A9 ? ? ? ? 76 ? 25 ? ? ? ? "
        "3D ? ? ? ? 74 ? 65 48 8B 04 25 ? ? ? ? 8B 0D ? ? ? ? 8B 1F BA ? ? ? ? C6 84 24 90 00 00 00 ? 48 8B 0C C8 8B "
        "04 0A 39 05 ? ? ? ? 7F ? 48 8D 94 24 90 00 00 00 8B CB E8 ? ? ? ? 48 8B 5C 24 70")))(
        result, lBaseNode, lResourceHandle, lStartMatrix, lbRelative);
}

TkAddNodesHandle *cTkEngineUtils::AddNodesStep(
    TkAddNodesHandle *result, TkHandle lParent, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lSceneGraphRes,
    const cTkMatrix34 *lTransformMatrix, bool lbRelative, int liMaxNumNodesToAdd)
{
    typedef TkAddNodesHandle *(*fn_type)(
        TkAddNodesHandle *result, TkHandle lParent, TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lSceneGraphRes,
        const cTkMatrix34 *lTransformMatrix, bool lbRelative, int liMaxNumNodesToAdd);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(renms_sdk::SignatureScan(
        "48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 57 48 81 EC ? ? ? ? 0F 29 70 E8 49 8B F1 0F 29 78 D8 41 8B D8")))(
        result, lParent, lSceneGraphRes, lTransformMatrix, lbRelative, liMaxNumNodesToAdd);
}

TkHandle *cTkEngineUtils::AddNodesStep(TkHandle *result, TkAddNodesHandle *lHandle, int liMaxNumNodesToAdd)
{
    typedef TkHandle *(*fn_type)(TkHandle *result, TkAddNodesHandle *lHandle, int liMaxNumNodesToAdd);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(renms_sdk::SignatureScan(
        "48 89 5C 24 08 57 48 83 EC ? 48 8B F9 48 8B DA 8B 4A 40")))(result, lHandle, liMaxNumNodesToAdd);
}

std::function<bool(TkHandle)> *cTkEngineUtils::FindNode(
    std::function<bool(TkHandle)> *result, TkHandle lNode, uint32_t luNameHash, int liType)
{
    typedef std::function<bool(TkHandle)> *(*fn_type)(
        std::function<bool(TkHandle)> *result, TkHandle lNode, uint32_t luNameHash, int liType);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(renms_sdk::SignatureScan(
        "40 53 48 83 EC ? 48 8B D9 C7 01 ? ? ? ? 45 8B D1")))(result, lNode, luNameHash, liType);
}

std::function<bool(TkHandle)> *cTkEngineUtils::FindNode(
    std::function<bool(TkHandle)> *result, TkHandle lNode, const char *lpacName, int liType)
{
    typedef std::function<bool(TkHandle)> *(*fn_type)(
        std::function<bool(TkHandle)> *result, TkHandle lNode, const char *lpacName, int liType);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(
        renms_sdk::SignatureScan("4C 89 44 24 18 53 48 81 EC ? ? ? ? 45 8B D1")))(result, lNode, lpacName, liType);
}

TkHandle *cTkEngineUtils::FindNodeContainingString(
    TkHandle *result, TkHandle lNode, cTkFixedString<128, char> *lpacName, int liType)
{
    typedef TkHandle *(*fn_type)(TkHandle *result, TkHandle lNode, cTkFixedString<128, char> *lpacName, int liType);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(renms_sdk::SignatureScan(
        "48 89 5C 24 08 48 89 74 24 10 57 48 81 EC ? ? ? ? 48 8D 44 24 70")))(result, lNode, lpacName, liType);
}

TkHandle *cTkEngineUtils::GetGroupNode(TkHandle *result, TkHandle lNode)
{
    typedef TkHandle *(*fn_type)(TkHandle *result, TkHandle lNode);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(
        renms_sdk::SignatureScan("48 89 5C 24 08 57 48 83 EC ? 8B DA 48 8B F9 90")))(result, lNode);
}

TkHandle *cTkEngineUtils::GetMasterModelNode(TkHandle *result, TkHandle lNode, eMasterModelNodeDistance lDistance)
{
    typedef TkHandle *(*fn_type)(TkHandle *result, TkHandle lNode, eMasterModelNodeDistance lDistance);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(renms_sdk::SignatureScan(
        "48 89 5C 24 10 48 89 74 24 18 57 48 83 EC ? 41 8B F0 48 8B F9")))(result, lNode, lDistance);
}

bool cTkEngineUtils::GetMatricesFromNode(TkHandle lHandle, cTkMatrix34 *lAbsoluteMatrix, cTkMatrix34 *lRelativeMatrix)
{
    typedef bool (*fn_type)(TkHandle lHandle, cTkMatrix34 *lAbsoluteMatrix, cTkMatrix34 *lRelativeMatrix);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(
        renms_sdk::SignatureScan("48 83 EC ? 49 8B C0 48 85 D2")))(lHandle, lAbsoluteMatrix, lRelativeMatrix);
}

TkHandle *cTkEngineUtils::GetModelNode(TkHandle *result, TkHandle lNode)
{
    typedef TkHandle *(*fn_type)(TkHandle *result, TkHandle lNode);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(renms_sdk::SignatureScan(
        "40 53 48 83 EC ? 48 8B D9 E8 ? ? ? ? 48 8B C3 48 83 C4 ? 5B C3 CC CC CC CC CC CC CC CC CC 48 83 EC ?")))(
        result, lNode);
}

TkStrongType<int, TkStrongTypeIDs::TkResHandleID> *cTkEngineUtils::GetResHandleFromNode(
    TkStrongType<int, TkStrongTypeIDs::TkResHandleID> *result, TkHandle lNode, cTkResourceDescriptor *lResDesc)
{
    typedef TkStrongType<int, TkStrongTypeIDs::TkResHandleID> *(*fn_type)(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> *result, TkHandle lNode, cTkResourceDescriptor *lResDesc);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(renms_sdk::SignatureScan(
        "48 89 5C 24 08 48 89 74 24 10 55 57 41 56 48 8D AC 24 A0 FE FF FF")))(result, lNode, lResDesc);
}

cTkSeed *cTkEngineUtils::GetSeedFromNode(cTkSeed *result, TkHandle lNode)
{
    typedef cTkSeed *(*fn_type)(cTkSeed *result, TkHandle lNode);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(
        renms_sdk::SignatureScan("48 89 5C 24 08 57 48 83 EC ? 48 8B F9 48 8D 4C 24 70")))(result, lNode);
}

bool cTkEngineUtils::IsNodeImposter(TkHandle lNode)
{
    typedef bool (*fn_type)(TkHandle lNode);

    return reinterpret_cast<fn_type>(
        reinterpret_cast<uint64_t>(renms_sdk::SignatureScan("40 53 48 81 EC ? ? ? ? 8B D9")))(lNode);
}

bool cTkEngineUtils::ReadModelFileName(TkHandle lModelNode, cTkFixedString<128, char> *lFilenameOut)
{
    typedef bool (*fn_type)(TkHandle lModelNode, cTkFixedString<128, char> *lFilenameOut);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(
        renms_sdk::SignatureScan("48 89 5C 24 08 57 48 83 EC ? 48 8B DA E8 ? ? ? ? 33 FF")))(lModelNode, lFilenameOut);
}

void cTkEngineUtils::RepositionGroupNode(TkHandle lGroupNode, const cTkVector3 *lDesiredPosition)
{
    typedef void (*fn_type)(TkHandle lGroupNode, const cTkVector3 *lDesiredPosition);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(renms_sdk::SignatureScan(
        "48 89 5C 24 08 57 48 81 EC ? ? ? ? 0F 28 05 ? ? ? ? 48 8B FA")))(lGroupNode, lDesiredPosition);
}

void cTkEngineUtils::RequestTexturesAlwaysResident(TkHandle lBaseNode, bool lbValue)
{
    typedef void (*fn_type)(TkHandle lBaseNode, bool lbValue);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(
        renms_sdk::SignatureScan("48 83 EC ? 48 8D 05 ? ? ? ? 88 54 24 28")))(lBaseNode, lbValue);
}

void cTkEngineUtils::SetNodeActive(TkHandle lHandle, bool lbActive)
{
    typedef void (*fn_type)(TkHandle lHandle, bool lbActive);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(renms_sdk::SignatureScan(
        "E9 ? ? ? ? CC CC CC CC CC CC CC CC CC CC CC E9 ? ? ? ? CC CC CC CC CC CC CC CC CC CC CC F7 C1 ? ? ? ?")))(
        lHandle, lbActive);
}

void cTkEngineUtils::SetNodeActiveRecursive(TkHandle lHandle, bool lbActive)
{
    typedef void (*fn_type)(TkHandle lHandle, bool lbActive);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(
        renms_sdk::SignatureScan("E9 ? ? ? ? CC CC CC CC CC CC CC CC CC CC CC F7 C1 ? ? ? ?")))(lHandle, lbActive);
}

void cTkEngineUtils::SetNodeMatrixWorld(TkHandle lHandle, const cTkMatrix34 *lMatrix)
{
    typedef void (*fn_type)(TkHandle lHandle, const cTkMatrix34 *lMatrix);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(renms_sdk::SignatureScan(
        "F7 C1 ? ? ? ? 0F 86 ? ? ? ? 4C 8B DC 49 89 5B 10 57 48 81 EC ? ? ? ? 8B C1 48 8B FA 25 ? ? ? ? 8B D9 3D ? ? ? "
        "? 0F 84 ? ? ? ? 85 C0 0F 84 ? ? ? ? 41 0F 29 73 E8")))(lHandle, lMatrix);
}

void cTkEngineUtils::SetNodeMatrixWorld(TkHandle lHandle, const cTkPhysRelMat34 *lMatrix)
{
    typedef void (*fn_type)(TkHandle lHandle, const cTkPhysRelMat34 *lMatrix);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(renms_sdk::SignatureScan(
        "F7 C1 ? ? ? ? 0F 86 ? ? ? ? 4C 8B DC 49 89 5B 10 57 48 81 EC ? ? ? ? 8B C1 48 8B FA 25 ? ? ? ? 8B D9 3D ? ? ? "
        "? 0F 84 ? ? ? ? 85 C0 0F 84 ? ? ? ? 0F 28 05 ? ? ? ?")))(lHandle, lMatrix);
}

void cTkEngineUtils::SetNodeParent(TkHandle lNode, TkHandle lParent, bool lbPreserveTransforms)
{
    typedef void (*fn_type)(TkHandle lNode, TkHandle lParent, bool lbPreserveTransforms);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(renms_sdk::SignatureScan(
        "48 89 5C 24 08 44 88 44 24 18 89 54 24 10 55 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 D9")))(
        lNode, lParent, lbPreserveTransforms);
}

void cTkEngineUtils::SetSceneNetworkId(TkHandle lNode, const char *lId, uint32_t lIndex, bool lbIncludeAttachments)
{
    typedef void (*fn_type)(TkHandle lNode, const char *lId, uint32_t lIndex, bool lbIncludeAttachments);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(
        renms_sdk::SignatureScan("40 53 55 57 48 83 EC ? 0F B6 02")))(lNode, lId, lIndex, lbIncludeAttachments);
}

SKYSCRAPER_END