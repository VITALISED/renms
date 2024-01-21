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
#include <toolkit/graphics/shader/TkVertexDefinition.h>
#include <toolkit/graphics/shader/TkVertexLayoutRuntime.h>
#include <toolkit/simulation/physics/TkLDSWind.h>
#include <toolkit/system/thread/TkSpinMutex.h>
#include <toolkit/utilities/containers/TkLinearHashTable.h>
#include <toolkit/utilities/containers/TkStackContainer.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <toolkit/scene/geometry/tkgeometrydata.meta.h>
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
    cTkVector<uint64_t> maMeshNameHashes;
    cTkVector<uint64_t> maDoubleBufferedMeshNameHashes;
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

/**
 * @class cEgGeometryResource
 * @brief Class based on Horde3D struct Horde3D::GeometryResource, see
 * https://github.com/horde3d/Horde3D/blob/master/Horde3D/Source/Horde3DEngine/egGeometry.h
 */
class cEgGeometryResource : public cEgResource
{
  public:
    virtual ~cEgGeometryResource();
    virtual cTkResource *Clone();
    virtual void CloneInternal(const cTkResource *);
    virtual void Release();
    virtual void InitDefault();
    virtual bool Load(const char *, int);
    virtual int GetElementCount(int);
    virtual int GetElementParamInt(int, int, int);
    virtual void SetElementParamInt(int, int, int, int);
    virtual void *MapResStream(int, int, int, bool, bool, const char *);
    virtual uint32_t GetDeletionFrameDelay();

    void SetSkinnedVertexData(int liVertIndex, const cTkSkinnedVertexData &lData);
    const AnimTransform *GetBindTransform(uint32_t luJointIndex);
    int64_t GetIndexBufferHandle(int liGeometryBufferIndex);
    void GetSkinnedVertexData(
        int liVertex, uint32_t liAlitidIndex, cTkSkinnedVertexData &lData, char *lpaVertexStreamIn);
    int64_t GetVertexBufferHandle(int liGeometryBufferIndex);
    void InsertElement(char *lpVertexData, int, const cTkVector2 &lVector, const cTkVertexElement *lpVertexElement);
    void InsertElement(char *lpVertexData, int, const cTkVector3 &lVector, const cTkVertexElement *lpVertexElement);
    void InsertElement(char *lpVertexData, int, const cTkVector4 &lVector, const cTkVertexElement *lpVertexElement);
    void *MapResStream(int liElem, int liElemIdx, int liStream, bool lbRead, bool lbWrite);
    bool ParseData(cTkGeometryData &lData);
    void ReleaseVertexBuffer(int iVertBuf);
    void SetSkinnedVertexData(
        int liVertIndex, const cTkSkinnedVertexData &lData, char *lpaVertexStream, int liStreamIndex);
    void UpdateDynamicVertData(uint32_t liAltidIndex);

    static void FactoryFunc(const std::string &lsName, int liFlags, cTkResourceDescriptor *lpResourceDescriptor);

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
};

SKYSCRAPER_END