/**
 * @file GcProjectileManager.h
 * @author VITALISED & Contributors
 * @since 2023-12-07
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

#include <networking/GcNetworkRpcCall.h>
#include <simulation/particles/GcEffectList.h>
#include <simulation/projectiles/GcProjectile.h>
#include <toolkit/utilities/containers/TkUnorderedMap.h>

#include <simulation/projectiles/gcprojectiledatatable.meta.h>

SKYSCRAPER_BEGIN

class cGcProjectileManager
{
  public:
    class cGcResourceBlob
    {
      public:
        TkHandle mNode;
        cTkPhysRelVec3 mPosition;
        cTkAttachmentPtr mpTarget;
        cTkVector3 mVelocity;
        cTkVector3 mOffset;
        cTkVector3 mAxis;
        int miAmount;
        float mfScale;
        float mfRotate;
        float mfStartTime;
        float mfTotalTime;
        TkID<128> mSubstance;
        bool mbIsRemote;
    };

    struct MiningTracker
    {
        int miMinedCount;
        float mfLastMinedTime;
    };

    cGcRpcCallBase *SHOH;
    cGcRpcCallBase *ROSH;
    cGcRpcCallBase *BLOB;
    cGcRpcCallBase *SSNH;
    cGcProjectileDataTable *mpDataTable;
    cGcEffectList<cGcProjectile, 4096> mProjectiles;
    bool mbContructed;
    bool mbPrepared;
    cTkSmartResHandle mDefaultBlobRes;
    cGcProjectileManager::MiningTracker maiMiningCount[3];
    std::array<TkAudioObject, 32> mProjectileAudioObjectArray;
    unsigned int mProjectileAudioIndex;
    cTkUnorderedMap<TkID<128>, cGcProjectileData *, TkIDUnorderedMap::Hash128> mProjectileIDMap;
    cTkUnorderedMap<TkID<128>, cGcLaserBeamData *, TkIDUnorderedMap::Hash128> mLaserIDMap;
    cTkVector<cTkSmartResHandle> mLoadedResources;
    cGcProjectileImpact mLastPlayerImpact;
    cTkVector<cGcProjectileManager::cGcResourceBlob> maResourceBlobs;
    cTkVector3 mLastEditPos;
    float mfLastEditRadius;
};

SKYSCRAPER_END