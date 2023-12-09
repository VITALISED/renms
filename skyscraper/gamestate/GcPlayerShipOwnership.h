/**
 * @file GcPlayerShipOwnership.h
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

#include <simulation/player/GcPersonalTeleporter.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/core/types/TkHandle.h>
#include <toolkit/graphics/utilities/TkModelResourceRenderer.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>

#include <simulation/customisation/gccustomisationcomponentdata.meta.h>
#include <simulation/player/gcscaneffectdata.meta.h>
#include <simulation/spaceship/gcspaceshipcomponentdata.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerShipOwnership
{
  public:
    enum eMeshRefreshState
    {
        ReadyForRefresh,
        Generating,
        SwapMesh,
    };

    struct sGcShipData
    {
        cTkSeed mPlayerShipSeed;
        cTkSmartResHandle mPlayerShipResHandle;
        TkHandle mPlayerShipNode;
        cTkAttachmentPtr mpPlayerShipAttachment;
        int mFreighterDockIndex;
        cGcCustomisationComponentData mShipCustomisationData;
    };

    struct RetiredShipRecord
    {
        cTkSmartResHandle mShipResHandle;
        TkHandle mShipNode;
    };

    std::unordered_map<int, std::function<void(cTkMatrix34 const &)>> mNewSpaceshipSpawnCallbacks;
    TkHandle mGroupRootNode;
    cGcPlayerShipOwnership::sGcShipData mShips[12];
    cTkMatrix34 mPlayerShipTMWhenLastDestroyed;
    cTkMatrix34 mNewShipDelayedSpawnMatrix;
    const cGcSpaceshipComponentData *mpPrimaryShipComponentData;
    int miCachedShipComponentDataIndex;
    cTkModelResourceRenderer maThumbnailRenderers[12];
    cGcPlacementArc mPlacementArc;
    cTkVector2 mInitialPlacementDirection;
    float mfPlacementRotation;
    bool mbUseOffHandForPlacementRotation;
    cTkVector<cGcPlayerShipOwnership::RetiredShipRecord> mRetiredShips;
    bool mbShowShipPreview;
    int miShipToPreview;
    int miCurrentPreviewShip;
    TkHandle mPreviewShipNode;
    cTkPhysRelMat34 mLastKnownPreviewMatrix;
    cTkPhysRelMat34 mLastGoodPreviewMatrix;
    bool mbLastGoodPreviewMatrixValid;
    cGcScanEffectData mShipPreviewScanData;
    float mfShipPreviewFirstActiveTime;
    float mfShipPreviewLastActiveTime;
    cTkVector3 mShipPreviewScale;
    cTkColour mShipPreviewColour;
    bool mbShouldRefreshMesh;
    cGcPlayerShipOwnership::eMeshRefreshState mMeshRefreshState;
    cTkSmartResHandle mRefreshSwapRes;
    bool mbNextSummonIsFree;
};

SKYSCRAPER_END