/**
 * @file TkGraphicsManager.h
 * @author VITALISED & Contributors
 * @since 2023-12-11
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

#include <engine/source/engine/EgMain.h>
#include <toolkit/core/types/TkHandle.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>
#include <toolkit/resources/TkResource.h>

SKYSCRAPER_BEGIN

class cTkGraphicsManagerBase
{
  public:
    enum EViewMode
    {
        eViewNormal,
        eViewDebug,
        eViewWireframe,
        eViewMode_Num,
    };

    enum eScreenFilter
    {
        Default,
        Dummy1,
        Dummy2,
        Dummy3,
        Dummy4,
        Dummy5,
        _NumFilters,
    };

    TkHandle mCameraNode;
    TkHandle mStereoCameraNodes[2];
    TkHandle mCameraGroupNode;
    cTkSmartResHandle mDefaultPipelineRes;
    cTkVector2 mViewportOffset;
    cTkVector2 mViewportSize;
    cTkGraphicsManagerBase::EViewMode meViewMode;
    int miScreenWidth;
    int miScreenHeight;
    float mfNearClip;
    float mfFarClip;
    float mfFovScale;
    cTkGraphicsManagerBase::eScreenFilter meScreenshotFilter;
    bool mbScreenshotModeActive;

    virtual ~cTkGraphicsManagerBase();
    virtual void Construct(int, int);
    virtual bool Prepare(const char *);
    virtual void Update(float);
    virtual void UpdateRender();
    virtual void NextViewMode();
    virtual void SetDimensions(int, int, float, float);
    virtual EgRenderQueueHandle EnqueueRender(
        const cTkPhysRelMat34 *, const cTkPhysRelMat34 *, float, float, bool, EgRenderCullMode::Mode, EgRenderView,
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID>);
    virtual EgRenderQueueHandle EnqueueRenderStereo(
        const cTkPhysRelMat34 *, const cTkPhysRelMat34 *, const cTkPhysRelMat34 *, const cTkPhysRelMat34 *,
        const cTkPhysRelMat34 *, const cTkPhysRelMat34 *, float, float, bool, bool, EgRenderCullMode::Mode,
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID>);
    virtual void ResizeBuffers(cTkVector2);
    virtual EgRenderQueueHandle EnqueueRenderViewport(
        const cTkPhysRelMat34 *, const cTkPhysRelMat34 *, float, float, cTkVector2, cTkVector2, bool,
        EgRenderCullMode::Mode, EgRenderView, TkStrongType<int, TkStrongTypeIDs::TkResHandleID>);
    virtual EgRenderQueueHandle EnqueueRenderViewportStereo(
        const cTkPhysRelMat34 *, const cTkPhysRelMat34 *, const cTkPhysRelMat34 *, const cTkPhysRelMat34 *,
        const cTkPhysRelMat34 *, const cTkPhysRelMat34 *, float, float, cTkVector2, cTkVector2, bool, bool,
        EgRenderCullMode::Mode, TkStrongType<int, TkStrongTypeIDs::TkResHandleID>);
    virtual void PatchRenderTargetMatrices(
        const cTkPhysRelMat34 *, const cTkPhysRelMat34 *, const cTkPhysRelMat34 *, const cTkPhysRelMat34 *,
        const cTkPhysRelMat34 *, const cTkPhysRelMat34 *, float, float, cTkVector2, cTkVector2, EgRenderCullMode::Mode,
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID>);
    virtual cTkMatrix34 *GetViewMatrix(cTkMatrix34 *result);
    virtual cTkMatrix44 *GetProjectionMatrix(cTkMatrix44 *result);
    virtual bool InFrustum(const cTkVector3 *, const cTkVector3 *);
    virtual bool Release();
    virtual void Destruct();
    virtual bool IsConstructed();
    virtual float CalculateNewFov(float);
    virtual void EnqueueRenderPipeline(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID>, EgRenderCullMode::Mode, TkHandle);
    virtual void EnqueueRenderToTexture(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID>, TkStrongType<int, TkStrongTypeIDs::TkResHandleID>,
        const cTkMatrix34 *, const cTkMatrix34 *, float, float, EgRenderCullMode::Mode, bool, TkHandle);
    virtual void EnqueueRenderToTexture(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID>, TkStrongType<int, TkStrongTypeIDs::TkResHandleID>,
        const cTkPhysRelMat34 *, const cTkPhysRelMat34 *, float, float, EgRenderCullMode::Mode, bool, TkHandle);
    virtual void EnqueueRenderToTexture(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID>, TkStrongType<int, TkStrongTypeIDs::TkResHandleID>,
        const cTkMatrix34 *, float, float, EgRenderCullMode::Mode, bool, bool, TkHandle);
    virtual void EnqueueRenderToTexture(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID>, TkStrongType<int, TkStrongTypeIDs::TkResHandleID>,
        EgRenderCullMode::Mode, TkHandle);
    virtual void SetShadowCascadeMask(int);
    virtual void SetMotionBlur(float, float, float);
};

class cTkGraphicsManager : public cTkGraphicsManagerBase
{
  public:
    bool mbNonStandardResolution;
    float mfNonStandardAspectRatio;
    bool mbNonStandardOutputAspect;
    float mfNonStandardOutputAspectFactor;
    float mfMblurTimestep;
    float mfMblurShutterSpeed;
    float mfMblurShutterAngle;
    bool mbConstructed;
};

SKYSCRAPER_END