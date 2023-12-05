/**
 * @file EgGeometry.h
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

#include <engine/source/engine/EgPrimatives.h>
#include <engine/source/engine/EgResource.h>
#include <toolkit/animation/utils/TkIKSolver.h>
#include <toolkit/graphics/shader/TkVertexLayoutRuntime.h>
#include <toolkit/simulation/physics/TkLDSWind.h>
#include <toolkit/system/thread/TkSpinMutex.h>
#include <toolkit/utilities/containers/TkLinearHashTable.h>
#include <toolkit/utilities/containers/TkStackContainer.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <toolkit/scene/geometry/tkjointmirroraxis.meta.h>

SKYSCRAPER_BEGIN

class cEgGeometryResource;

namespace GeometryStreaming
{

class cEgGeometryStreamer
{
    enum eGeometryStreamState
    {
        EGSS_None,
        EGSS_Requested,
        EGSS_Ready,
        EGSS_Released,
    };

    class cBufferData
    {
        uint64_t mu64NameHash;
        uint32_t mauVertexBufferHandle[2];
        uint32_t mauIndexBufferHandle[2];
        int32_t miRefCount;
        GeometryStreaming::cEgGeometryStreamer::eGeometryStreamState meState;
        bool mb16bitIndices;
    };

    class cRenderThreadData
    {
        cTkVector<GeometryStreaming::cEgGeometryStreamer::cBufferData> mBufferLookup;
    };

    class cMeshDescriptorData
    {
        TkID<256> mOldId;
        TkID<256> mNewId;
        bool mbIsProcMesh;
    };

    GeometryStreaming::cEgGeometryStreamer::cRenderThreadData mRenderThreadData;
    cEgGeometryResource *mpGeometry;
    int miNumMeshes;
    cTkVector<cTkFixedString<128, char>> maMeshNames;
    cTkVector<cTkFixedString<128, char>> maLODMeshNames;
    cTkVector<unsigned __int64> maMeshNameHashes;
    cTkVector<unsigned __int64> maDoubleBufferedMeshNameHashes;
    robin_hood::detail::Table<true, 80, int, void, robin_hood::hash<int, void>, std::equal_to<int>>
        mDoubleBufferedMeshes;
    cTkVector<bool> mabIsMeshProcedural;
    cTkLinearHashTable<int, GeometryStreaming::cEgGeometryStreamer::cMeshDescriptorData, cTkLinearHashTableHash<int>>
        mMeshDescriptorHashTable;
    cTkVector<unsigned int> mauIndexBufferOffsets;
    cTkVector<unsigned int> mauVertexBufferOffsets;
    cTkVector<unsigned int> mauIndexBufferSizes;
    cTkVector<unsigned int> mauVertexBufferSizes;
    cTkVector<GeometryStreaming::cEgGeometryStreamer::cBufferData> mBufferLookup;
    cTkSpinMutex mBufferHashmapMutex;
    cTkVector<int> maFileIoHandlesInFlight;
    cTkSpinMutex mCloneMutex;
};

} // namespace GeometryStreaming

class cEgModelNode;

class cEgGeometryAABBCache
{
    cTkStackVector<cEgBoundingBox, 1> maBoundingBoxes;
    cTkStackVector<bool, 1> maDirty;
};

class cEgGeometryResource : public cEgResource
{
    uint32_t muIndexBuffer;
    cTkStackVector<uint32_t, 1> maVertexBuffers;
    cTkStackVector<uint32_t, 1> maSmallVertexBuffers;
    uint32_t muIndexCount;
    uint32_t muVertexCount;
    uint32_t muBvVertexCount;
    bool mb16BitIndices;
    char *mpIndexData;
    cTkStackVector<cTkVector3 *, 1> mpaVertPositionData;
    cTkStackVector<cEgGeometryAABBCache, 1> maAABBCaches;
    cTkStackVector<char *, 1> mpaVertStreams;
    cTkStackVector<cTkWindEigenvectors *, 1> mpaWindEigenvectorSets;
    cTkStackVector<uint64_t, 1> maAltIdHashes;
    cTkStackVector<int32_t, 1> maAltIdRefCounts;
    cTkStackVector<int32_t, 1> mMeshVertRStart;
    cTkStackVector<int32_t, 1> mMeshVertREnd;
    cTkStackVector<int32_t, 1> mMeshBvVertStart;
    cTkStackVector<int32_t, 1> mMeshBvVertEnd;
    cTkVector<cEgJoint> mJoints;
    cTkVector<AnimTransform> mBindPose;
    cEgBoundingBox mBoundingBox;
    cEgBoundingBox mSkeletonAABB;
    cTkVector<cEgBoundingBox> mJointAABBs;
    cTkVector<cTkVector3> mJointVertMeans;
    cTkVector<cTkVector3> mJointVertStdDevs;
    cTkVector<int> mJointMirrorInds;
    cTkVector<cTkJointMirrorAxis> mJointMirrorAxis;
    cTkVector<cEgMorphTarget> mMorphTargets;
    cTkVector<int> mSkinMatOrder;
    cTkVector<int> mMeshBaseSkinMat;
    unsigned int muMinMorphIndex;
    unsigned int muMaxMorphIndex;
    cTkVertexLayoutRT mVertexLayout;
    cTkVertexLayoutRT mSmallVertexLayout;
    cTkVector<cEgModelNode *> mModelNodesThatUseThisGeometry;
    GeometryStreaming::cEgGeometryStreamer mStreamManager;

    ~cEgGeometryResource();
    cTkResource *Clone();
    void CloneInternal(const cTkResource *);
    void Release();
    void InitDefault();
    bool Load(const char *, int);
    int GetElementCount(int);
    int GetElementParamInt(int, int, int);
    void SetElementParamInt(int, int, int, int);
    void *MapResStream(int, int, int, bool, bool, const char *);
};

SKYSCRAPER_END