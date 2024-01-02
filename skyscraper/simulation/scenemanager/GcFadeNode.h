/**
 * @file GcFadeNode.h
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

#include <toolkit/core/types/TkHandle.h>
#include <toolkit/resources/TkResource.h>
#include <toolkit/utilities/containers/TkStackContainer.h>

SKYSCRAPER_BEGIN

enum eFadeState
{
    EFade_In,
    EFade_Out,
    EFade_Visible,
    EFade_Hidden,
};

enum eFadeType : uint8_t
{
    FadeInThenFadeOut,
    CrossFade,
};

enum eImposterLevelCaptured
{
    None_,
    Early,
    Basic,
    WithGeometry,
    SecondMip,
    AllTextures,
};

class cGcFadeNodeBase
{
  public:
    float mfTimer;
    float mfTotalTime;
    int miNodeParam;
    int miNodeSetIndex;
    eFadeState meFadeState;
    eFadeType meFadeType;

    virtual void SetNodeActivation(bool);
    virtual void CheckNodeActivation(bool);
    virtual void SetNodeParamF(float);
    virtual bool Update();
};

class cGcFadeNodeInstance : public cGcFadeNodeBase
{
  public:
    class cImposterGenerationData
    {
      public:
        cTkFixedString<512, char> msFullPath;
        TkHandle mNodeToRender;
        cTkSmartResHandle mNodeToRenderResource;
        cTkSmartResHandle mPipelineResource;
        cTkSmartResHandle mPipelineResourceNormals;
        cTkSmartResHandle mPipelineResourceMasks;
        int miPipelineSetRenderTargetPipelineStage;
        int miPipelineNormalsSetRenderTargetPipelineStage;
        int miPipelineMasksSetRenderTargetPipelineStage;
        int miPipelineClearRenderTargetPipelineStage;
        int miPipelineNormalsClearRenderTargetPipelineStage;
        int miPipelineMasksClearRenderTargetPipelineStage;
        int miPipelineDrawPipelineStage;
        int miPipelineNormalsDrawPipelineStage;
        int miPipelineMasksDrawPipelineStage;
        cTkSmartResHandle mDxt5DiffuseTexRes;
        cTkSmartResHandle mDxt5NormalTexRes;
        cTkSmartResHandle mDxt5MaskTexRes;
        cTkSmartResHandle mTempMaterialRes;
        float mfCentreOffset;
        float mfAspectRatio;
        float mfDistance;
        float mfHeight;
        float mfOriginalHeight;
        float mfHeightOffset;
        float mfImposterWidthMultiplier;
        float mfWidth;
        float mfImposterFadeDistance;
        cTkResourceDescriptor mResourceDescriptor;
        cTkVector<cTkSmartResHandle> *mpImposterResources;
        int miRefCount;
        bool mbAbort;
        int miImposterGenerationStateIndex;
        eImposterLevelCaptured meImposterLevelToCapture;
    };

    cTkStackVector<TkHandle, 10> maMeshNodeHandles;
    TkHandle mTransientRenderNode;
    int miNumImposterImages;
    bool mbPrepared;
    int miWaitingForGeometryStreaming;
    int miImposterGenerationStateIndex;
    cGcFadeNodeInstance::cImposterGenerationData *mpGenerationData;
    cTkVector<cTkSmartResHandle> mImposterResources;
};

class cGcFadeNode : public cGcFadeNodeBase
{
  public:
    TkHandle mNode;
};

SKYSCRAPER_END