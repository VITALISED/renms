/**
 * @file EgPipeline.h
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

#include <engine/source/engine/EgResource.h>
#include <toolkit/graphics/2d/texture/TkTextureBase.h>

SKYSCRAPER_BEGIN

class PCParam
{
  public:
    virtual ~PCParam();
};

class PipelineCommands
{
  public:
    enum List
    {
        DrawGeometry,
        DrawShadowGeometry,
        DrawQuad,
        DrawQuadMT,
        DrawBboxes,
        DoForwardLightLoop,
        DoDeferredLightLoop,
        DoDeferredLightLoopMulti,
        SetUniform,
        UpdateShadowMap,
        SetShadowMap,
        BeginTiling,
        EndTiling,
        PushMarker,
        PopMarker,
        SetSubtileSize,
        UnsetSubtileSize,
        BeginTarget,
        EndTarget,
        SwapTargets,
        ClearTarget,
        ClearCullBuffers,
        ClearCullDrawCounts,
        BeginBuildCullBuffers,
        EndBuildCullBuffers,
        BuildCullBuffer,
        CopyTextureToTarget,
        TakeScreenshot,
        SetContext,
        ColourMaskSet,
        SetDepthBufferControl,
        BindBuffer,
        UnbindBuffers,
        FlushBuffer,
        SyncGraphicsToCompute,
        SyncComputeToGraphics,
        StartPrevFrameAsync,
        SetShaderControl,
        DiscardTargetContents,
        DrawHiddenAreaMesh,
        GenerateMips,
        ApplyDLSS,
        ApplyFFXSR2,
        ApplyXESS,
        FfxFsr2UpdateShaderConsts,
        FfxFsr2Pass,
        FfxFsr2Draw,
        FfxFsr2Barrier,
        CountDrawSamples,
        PauseTextureStreaming,
        ResumeTextureStreaming,
        BeginCheckerboard,
        EndCheckerBoard,
        SetSamplingRate,
        If_Open,
        If_Close,
        Conditions_Open,
        Conditions_Close,
        Else,
        EndIf,
        Condition,
    };
};

class cEgRenderTarget
{
  public:
    std::string msId;
    std::string msGroupId;
    std::string msCrossPipeShareId;
    std::string msScaleGroupId;
    std::string msScaleMulId;
    std::string msShareIds[6];
    int maiShareBufferRearrange[6];
    unsigned int muNumColourBuffers;
    uint8_t mFormat[24];
    unsigned int muWidth;
    unsigned int muHeight;
    unsigned int muSamples;
    float maScaleX[4];
    float maScaleY[4];
    float mfScaleFinalX;
    float mfScaleFinalY;
    unsigned int muRenderBuffer;
    int miNumUniformBuffers;
    int miNumSlices;
    bool mbHasDepthBuffer;
    bool mabColourUsesBackBuffer[6];
    bool mbDepthUsesBackBuffer;
    bool mbDepthUsesSharedTarget;
    uint8_t mDepthFormat[4];
    bool mbColourUsesSharedTarget;
    int miESRAMPageColBuf[6];
    int miESRAMPageDepthBuf;
    eTkTextureReductionMode maReductionMode[6];
    bool mabCanUseDcc[6];
    bool mbHasStencilBuffer;
    bool mbIsShadowBuffer;
    bool mbHasMips;
    bool mbAutoGenMips;
    bool mbMipsSRVs;
    bool mbDelayCreation;
    bool mbResScaling;
    bool mabPointSample[6];
    bool mbForceLinearLayout;
    bool mbVramOffset;
    bool mbPostUpscaleBuffer;
    bool mbIsOwnedByOtherPipe;
    bool mbApplyDynamicResScaling;
    bool mbApplied;
    bool mbEnabled;
};

class cEgPipelineCommand
{
  public:
    PipelineCommands::List mCommand;
    cTkVector<void *> mRefParams;
    cTkVector<PCParam *> mValParams;
    cTkVector<cTkTypedSmartResHandle<cTkResource>> mResParams;
    bool mbEnabled;
};

class cEgPipelineStage
{
  public:
    cTkVector<cEgPipelineCommand> mCommands;
    bool mbEnabled;
    std::string msId;
    int miIdHash;
};

class cEgPipelineResource : public cEgResource
{
  public:
    virtual void Release();
    virtual void InitDefault();
    virtual bool Load(const char *, int);
    virtual int GetElementCount(int);
    virtual int GetElementParamInt(int, int, int);
    virtual void SetElementParamInt(int, int, int, int);
    virtual const char *GetElementParamStr(int, int, int);

    bool CreateDelayedTempRenderTargets(uint32_t luWidth, uint32_t luHeight);
    bool CreateRenderTargets();
    void EnableRenderTargets();
    cEgRenderTarget *FindRenderTarget(const std::string &lsId);
    cTkVector2 &GetRenderTargetFinalScale(const cEgRenderTarget &lRenderTarget, bool lbAllowResScaling);
    bool ParseAndAddRenderTarget(const XMLNode &lNode2);
    bool ParseRenderTargetGroup(const XMLNode &lNode);
    const std::string &ParseStage(XMLNode &lNode, cEgPipelineStage &lStage);
    bool RaiseError(const std::string &lsMsg, int liLine);
    void ReleaseRenderTargets();

    static cEgPipelineResource *FactoryFunc(
        const std::string &lsName, int liFlags, cTkResourceDescriptor *lpResourceDescriptor);

    cTkVector<cEgRenderTarget> mRenderTargets;
    cTkVector<std::string> mRenderTargetsPendingCreation;
    cTkVector<cEgRenderTarget> mRenderTargetsDelayCreated;
    cTkVector<std::string> mRenderTargetsPendingDelayCreation;
    cTkVector<cEgPipelineStage> mStages;
    bool mbRenderTargetsCreated;
    bool mbResScalingDefault;
    TkID<128> mPipelineId;
};

SKYSCRAPER_END