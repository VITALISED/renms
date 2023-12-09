/**
 * @file GcTerrainEditsPersistentBuffer.h
 * @author VITALISED & Contributors
 * @since 2023-12-09
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

#include <networking/GcNetworkSynchronisedBuffer.h>
#include <toolkit/maths/geometry/TkAABB.h>
#include <toolkit/networking/TkUserIdBase.h>
#include <toolkit/utilities/containers/TkDeque.h>

#include <gamestate/interactions/gcterrainedit.meta.h>

SKYSCRAPER_BEGIN

struct sSharedMutex
{
    void *mMutex;
    bool mbMutexCreated;
};

struct sTerrainEditData
{
    union {
        int8_t miData8;
        struct
        {
            uint8_t mVoxelType : 3;
            uint8_t mShape : 1;
            uint8_t mCustom1 : 3;
            uint8_t mCustom2 : 1;
        };
    };
};

class cGcTerrainEditBlockBuffer : public cGcNetworkSynchronisedBuffer
{
  public:
    sSharedMutex *mSharedMutex;
    uint64_t mu64GalacticAddress;
    cTkAABB mEditsBoundingBox;
    cTkDeque<cGcTerrainEdit> mEdits;
    cTkUserIdBase<cTkFixedString<64, char>> mNetworkOwnerId;
    bool mbIsBaseProtected;
    int16_t miLastPlayerRequestTimestamp[31];
};

class cGcTerrainEditsPersistentBuffer
{
  public:
    struct sPendingEdit
    {
        cTkVector3 mPosition;
        sTerrainEditData mData;
        uint64_t mUA;
        char miExtraData;
        bool mbIsUndo;
        bool mbSetBaseProtected;
        bool mbJobId;
    };

    struct sPendingBlockJob
    {
        uint64_t mUA;
        cTkVector3 mAnchor;
        cTkVector3 mLimits;
        cTkUserIdBase<cTkFixedString<64, char>> mOwnerId;
        uint16_t mHashOffset;
        cTkDeque<cGcTerrainEdit> mEdits;
    };

    cGcTerrainEditBlockBuffer mBlockBuffers[256];
    int mBufferAges[256];
    uint64_t mCurrentGalacticAddress;
    int miNonEmptyBuffersCount;
    bool mbInitialised;
    int mCachedProtectedEditsCount;
    int mCachedProtectedBlocksCount;
    cGcTerrainEditsPersistentBuffer::sPendingEdit mPendingEdits[50000];
    std::atomic<int> miJobPendingEditIndex;
    int miJobProcessedEditIndex;
    std::atomic<int> mbEditJobRunning;
    bool mbCurrentJobId;
    void *mJobMutex;
    cGcTerrainEditsPersistentBuffer::sPendingBlockJob mPendingBlockJobs[256];
    int miBlockJobPendingIndex;
    int miBlockJobProcessedIndex;
};

SKYSCRAPER_END