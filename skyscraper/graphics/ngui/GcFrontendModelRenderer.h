/**
 * @file GcFrontendModelRenderer.h
 * @author VITALISED & Contributors
 * @since 2023-12-10
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

#include <gamestate/GcDiscoveryCommon.h>
#include <graphics/2d/GcProceduralTexture.h>
#include <graphics/frontend/pages/GcFrontendPageEnum.h>
#include <graphics/frontend/pages/data/GcDiscoveryPageData.h>
#include <graphics/ngui/GcNGuiLayer.h>
#include <toolkit/graphics/utilities/TkModelResourceRenderer.h>

#include <simulation/solarsystem/planet/gcplanetcolourdata.meta.h>

SKYSCRAPER_BEGIN

class cGcFrontendModelRenderer
{
  public:
    class cDiscoveryLoadRequest
    {
      public:
        enum eDiscoverLoadState
        {
            EDiscoveryLoadState_Complete,
            EDiscoveryLoadState_LoadResource,
            EDiscoveryLoadState_WaitForResource,
            EDiscoveryLoadState_TriggerRender,
            EDiscoveryLoadState_WaitForRender,
        };

        cTkSmartResHandle mDiscoveryResource;
        cGcDiscoveryData mDiscoveryData;
        cGcDiscoveryData mPlanetData;
        int miThumbnailRendererIndex;
        bool mbRequestStarted;
        cGcFrontendModelRenderer::cDiscoveryLoadRequest::eDiscoverLoadState meLoadState;
        cGcPlanetColourData mColourPalette;
        bool mbFurAllowed;
        bool mbClean;
        cGcProceduralTextureManager::TaskContext *mpTC;
    };

    cGcNGuiLayer *mpGuiRootNode;
    cGcNGuiLayer *mpPage;
    cTkSmartResHandle mModelResHandle;
    TkHandle mFocusNode;
    float mfFade;
    int miPrevMouseX;
    int miPrevMouseY;
    bool mbViewMouseActive;
    bool mbViewMouse3Active;
    cTkMatrix34 mModelRotationMatrix;
    float mfModelRotationX;
    float mfBlurredModelRotationX;
    float mfModelRotationY;
    float mfBlurredModelRotationY;
    float mfModelScaleFactor;
    cTkVector3 mvModelOffset;
    cTkSeed mPetBoneScaleSeed;
    float mfPetBabify;
    float mfFurScaler;
    bool mbFurAllowed;
    eFrontendPage meCurrentPage;
    eFrontendPage mePreviousPage;
    eFrontendPage meLastActivePage;
    cTkVector<cTkModelResourceRenderer> maModelResRenderers;
    cTkVector<float> maModelRendererActiveTimes;
    cTkModelResourceRenderer mBackgroundRenderer;
    cTkVector<cGcFrontendModelRenderer::cDiscoveryLoadRequest> mThumbnailRenderLoadRequests;
    cGcFrontendModelRenderer::cDiscoveryLoadRequest mMainDiscoveryModelLoadRequest;
    cTkVector<cTkModelResourceRenderer> mTkThumbnailRenderer;
    cTkVector<bool> mThumbnailRendererRefreshed;
    cTkModelResourceRenderer mSquadronShipThumbnailRenderer;
    cTkSmartResHandle mDefaultBGTexRes;
    cTkSmartResHandle mStaticDualPMapTexResFront;
    cTkSmartResHandle mStaticDualPMapTexResBack;
    cTkSmartResHandle mDefaultDiscoveryModelResHandle;
    bool mbRequestClearDiscoveryResources;
    int miDiscoveryThumbnailCurrentIndex;
    cTkVector2 mSmoothCdVelocity;
    cTkVector2 mSmoothCdFrom;
    bool mbShowScanEffect;
    bool mbShowingDefaultBackpack;
    bool mbPollModelUpdate;
    bool mbReturnToIdle;
    float mfCurrentAnimTimer;
    ePlanetDisplayTargetDisplayState mePreviousDiscoveryPageDisplayState;
};

SKYSCRAPER_END