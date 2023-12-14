/**
 * @file TkComponentManager.h
 * @author VITALISED & Contributors
 * @since 2023-12-14
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

#include <toolkit/core/types/TkTypes.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>
#include <toolkit/resources/TkResourceDescriptor.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <toolkit/utilities/containers/TkBitArray.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cTkComponentPool
{
  public:
    cTkFixedString<64, char> mType;
    cTkComponent *(*mpAllocateFunction)(int16_t, cTkComponent **, const char *);
    cTkComponent *(*mpConstructFunction)(cTkComponent *);
    void (*mpDestructFunction)(cTkComponent *);
    void (*mpLoadFunction)(
        cTkClassPointer *, const char *, cTkResourceDescriptor *, TkStrongType<int, TkStrongTypeIDs::TkResHandleID>);
    cTkComponentUpdater *mpUpdater;
    cTkComponent *maComponents;
    cTkComponent **mapComponentPtrs;
    uint64_t muTypeSize;
    uint64_t muMetadataTypeSize;
    int16_t *maiRoster;
    int16_t miPoolSize;
    int16_t miRosterPartition;
    int16_t miRosterPartitionMax;
    int16_t miPriority;
    cTkVector<cTkComponent *> mapOverflow;
};

class cTkComponentManager
{
  public:
    cTkComponentPool *maComponentPools[256];
    cTkComponentPool *maComponentPoolsUpdate[256];
    cTkComponentPool *maComponentPoolsRender[256];
    cTkComponentPool *maComponentPoolsPostPhysics[256];
    cTkBitArray<uint64_t, true, 256> mxComponentTypeMask[8];
    int miNumTypes;
    int miNumTypesUpdate;
    int miNumTypesRender;
    int miNumTypesPostPhysics;
    int miTypeMaskStackDepth;
    cTkPhysRelMat34 mCameraMatrixForUpdate;
    cTkBitArray<uint64_t, true, 256> mImGuiShowPool;
};

SKYSCRAPER_END