/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <skyscraper.h>
#include <simulation/player/GcPersonalTeleporter.h>
#include <toolkit/attachments/TkHandle.h>
#include <toolkit/resources/TkSmartResHandle.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/simulation/TkSeed.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/graphics/utilities/TkModelResourceRenderer.h>
#include <metadata/simulation/customisation/gccustomisationcomponentdata.meta.h>
#include <metadata/simulation/spaceship/gcspaceshipcomponentdata.meta.h>
#include <metadata/simulation/player/gcscaneffectdata.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerShipOwnership
{
public:
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

    enum eMeshRefreshState
    {
        ReadyForRefresh,
        Generating,
        SwapMesh,
    };

    std::unordered_map<int,std::function<void __cdecl(cTkMatrix34 const &)>> mNewSpaceshipSpawnCallbacks;
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