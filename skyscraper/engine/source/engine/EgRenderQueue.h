/**
 * @file EgRenderQueue.h
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

#include <engine/source/engine/EgPipeline.h>
#include <engine/source/engine/EgRendererBase.h>
#include <engine/source/engine/EgScene.h>
#include <toolkit/maths/numeric/TkIntrinsics.h>
#include <toolkit/system/thread/TkJobQueues.h>

SKYSCRAPER_BEGIN

class cEgRenderQueueEntry
{
  public:
    VecIntrinsics::V128Matrix mRenderSpaceTransform;
    cEgBoundingBox mBB_;
    union {
        struct
        {
            cEgRenderableSceneNode *mpNode;
            cEgMaterialResource *mpMatRes;
            cEgRenderQueueInfo *mpRenderQueueInfo;
            float mfAabbSqrDist;
            bool mbCullFullyInside;
            bool mbValid;
            bool maPadding[2];
        };
        uint8_t mAliasBuff[32];
    };
    uint8_t mBuffer[128];
};

class cEgUpdatableQueueEntry
{
  public:
    cEgSceneNode *mpNode;
    bool mbCullFullyInside;
    bool mbPadding[7];
};

class cEgRenderQueueBuffer
{
  public:
    void CalculateDepthValue(const cTkVector3 *lpCameraPosition);
    cEgRenderQueueEntry **DuplicateEntries();

    struct EntryBlock
    {
        cEgRenderQueueEntry *mEntries;
        cEgRenderableSceneNode *maNodes[128];
        cEgRenderQueueBuffer::EntryBlock *mpNext;
    };

    cEgRenderQueueEntry **mpFinalBuffer;
    cEgRenderQueueEntry **mpSortedLists[5];
    bool mbSortsKicked[5];
    cEgRenderQueueBuffer::EntryBlock *mpTempBuffer;
    cEgRenderQueueBuffer::EntryBlock *mpLastBlock;
    unsigned int muNumEntries;
    unsigned int muCapacity;
    bool mbHasDepth;
};

class cEgRenderQueue
{
  public:
    struct FinaliseJobParams;

    void Finalise(
        cEgRenderQueueInfo *lpQueueInfo, const cEgFrustum &lFrustum, int liShadowSplitIndex, bool lbHiPriorityJobs);
    void FinaliseJob(cEgRenderQueue::FinaliseJobParams *lpParams);
    void FinaliseJobFunc(void *lpVoid);
    cEgRenderQueueBuffer &GetSortedRenderQueue(
        int liIndex, RenderingOrder::List leOrder, bool lbNeedsDepth, const cEgFrustum &lFrustum);
    void KickSortsForPipeline(const cEgPipelineResource *lpPipeline, const cEgFrustum &lFrustum);
    void PostCullUpdate(cEgRenderQueueInfo *lpQueueInfo, const cEgFrustum &lFrustum, int liShadowSplitIndex);

    struct FinaliseJobParams
    {
        cEgRenderQueue *mpQueue;
        const cEgFrustum *mpFrustum;
        int miShadowSplitIndex;
        cEgRenderQueueInfo *mpQueueInfo;
    };

    cEgRenderQueueBuffer *mpRenderableLists;
    int miNumRenderableLists;
    int miRenderableListCapacity;
    const cEgPipelineResource *mpPipelineResource;
    bool mbIsShadowQueue;
    cTkDependencyCounter mSortDepCounter;
    cEgUpdatableQueueEntry *mpPostCullUpdatableList;
    int miNumUpdatableEntries;
    int miUpdateListCapacity;
    std::atomic<int> mFinalisesTaken;
    std::atomic<int> mFinalisesComplete;
};

class cEgRenderQueueInfo
{
  public:
    cTkMatrix44 maLightMatrices[4];
    cTkVector3 mvRenderOffset;
    eEgRenderParity mParity;
    bool mbStereo;
    cEgShadowProperties mShadowMapProperties;
    cEgRenderCameraInfo mCameraInfo;
    cEgRenderCameraInfo mStereoCameraInfo[2];
    cEgRenderLightInfo mCurrentLight;
    cEgRenderLightInfo mGlobalLight;
    cEgRenderQueue *mpRenderQueue;
    std::array<cEgRenderQueue *, 3> mapShadowQueue;
    std::atomic<int> miLocalInflightCulls;
    std::atomic<int> *mpiInFlightCulls;
    bool mbHasShadowQueue;
};

SKYSCRAPER_END