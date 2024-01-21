/**
 * @file EgRendererBase.h
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

#include <engine/source/engine/EgLight.h>
#include <engine/source/engine/EgMaterial.h>
#include <engine/source/engine/EgPipeline.h>
#include <engine/source/engine/EgPrimatives.h>
#include <engine/source/engine/EgTexture.h>
#include <toolkit/maths/numeric/generic/TkMatrix44Generic.h>
#include <toolkit/maths/numeric/generic/TkVector4Generic.h>

SKYSCRAPER_BEGIN

enum eEgRenderParity
{
    eRenderParity_Single,
    eRenderParity_EvenRender,
    eRenderParity_OddRender,
};

class cEgShadowProperties
{
  public:
    int miViewports[3][4];
    float mfSplitDistances[3];
    float mfShadowMapBias[3];
    cTkVector4 mSplitMaxDims[3];
    float mfFrustumLength;
    float mfSubShadowmapScale;
    cTkVector4 mShadowMapSize;
    cTkVector4 mShadowFadeParam;
    float mfMinObjectPixelSize;
    int miNumberOfSplits;
    int miCurrentShadowMap;
    bool mbPerspectiveShadowmap;
    cEgFrustum mShadowCullFrustum[3];
    cEgFrustum mShadowCullInnerFrustum[2];
    cTkMatrix44 mShadowViewMatrix[3];
    cTkMatrix44 mShadowProjMatrix[3];
    cTkMatrix44 mShadowViewProjMatrix[3];
    float mafFarClips[3];
    cTkVector3 mvCachedShadowRenderOffset;
};

class cEgRenderCameraInfo
{
  public:
    cEgFrustum mFrustum;
    float mfNearClip;
    float mfFarClip;
    unsigned int miFrameIndex;
    unsigned int miFrameIndexLastJump;
    int miOutputBufferIndex;
    int miOutputCubeFace;
    int miMipToRenderTo;
    int miOccSet;
    int miImposterNumViews;
    float mfImposterClipDistance;
    float mfImposterWidth;
    float mfImposterHeight;
    cTkTypedSmartResHandle<cEgPipelineResource> mpPipelineRes;
    cTkTypedSmartResHandle<cEgTextureResource> mpOutputTex;
    cTkMatrix44 mProjectionMatrix;
    cTkMatrix44 mInverseProjectionMatrix;
    cTkMatrix44 mInverseProjectionSCMatrix;
    cTkMatrix44 mViewMatrixWithOffset;
    cTkMatrix44 mViewProjectionMatrix;
    cTkMatrix34 mCameraMatrix;
    cTkMatrix44 mInverseViewMatrixWithOffset;
    cTkMatrix44 mInverseViewMatrixWithOffset_NoHT;
    cTkMatrix44 mPrevProjectionMatrix;
    cTkMatrix44 mPrevViewMatrixWithOffset;
    cTkMatrix44 mPrevInverseViewMatrixWithOffset;
    cTkMatrix44 mThisToPrevViewProjectionMatrix;
    cTkVector4 mBlurSettings;
    cTkVector4 mTaaSettings;
    cTkVector4 mTessSettings;
    cTkVector4 mShellsSettings;
    cTkVector4 mDeJitterVec;
    cTkVector4 mvFovValues;
    cTkVector4 mCustomViewport;
    cTkVector4 *mpViewport;
    cTkVector4 *mpScissor;
    cTkVector4 *mpMultiCopy;
    cTkMatrix44 mProjectionMatrixNoJitter;
    cTkMatrix44 mPrevProjectionMatrixNoJitter;
    cTkMatrix44 mViewProjectionMatrixNoJitter;
    cTkMatrix44 mPrevViewProjectionMatrixNoJitter;
};

class cEgRenderLightInfo
{
  public:
    void SetFromLight(cEgLightNode *lpLight);
    void SetFromQueueEntry(const cEgRenderQueueEntry *lpEntry);

    cTkMatrix34 mRenderSpaceTransform;
    cTkVector3 mAbsolutePosition;
    cTkVector3 mRenderSpacePosition;
    cTkVector3 mSpotDirection;
    cTkVector3 mSpotUp;
    cTkColour mColour;
    TkID<128> msLightingContext;
    TkID<128> msShadowContext;
    cEgMaterialResource *mpMaterialResource;
    float mfRadius;
    float mfIntensity;
    float mfFov;
    float mfVolumetric;
    float mfFalloffType;
    bool mbHasLight;
    int miCookieIdx;
};

SKYSCRAPER_END