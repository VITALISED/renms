/**
 * @file GcGraphicsManager.h
 * @author VITALISED & Contributors
 * @since 2023-12-08
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

#include <graphics/2d/GcProceduralTexture.h>
#include <toolkit/graphics/2d/ui/objects/text/Tk2dTextPreset.h>
#include <toolkit/graphics/TkGraphicsManager.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <graphics/gcbootlogodata.meta.h>
#include <graphics/hud/gcfonttable.meta.h>
#include <toolkit/enginesettings/tkanimdetailsettingstable.meta.h>
#include <toolkit/enginesettings/tkgraphicsdetailpreset.meta.h>

SKYSCRAPER_BEGIN

class cGcLogoSequence
{
  public:
    enum State
    {
        NotStarted,
        WaitingToStart,
        FadeIn,
        Hold,
        FadeOut,
        ExitFade,
        Complete,
    };

    cGcBootLogoData *mpBootLogoData;
    uint64_t mu64StartTime;
    cGcLogoSequence::State meState;
    float mfTimer;
    float mfStateT;
    float mfExitFade;
    int miImage;
    int miMaxImages;
    std::array<cTkSmartResHandle, 4> maBootLogoRes;
};

class cGcGraphicsManager : public cTkGraphicsManager
{
  public:
    class cTkUniformData
    {
      public:
        cTkSmartResHandle mMaterial;
        cTkFixedString<128, char> macName;
        cTkVector4 mValue;
    };

    cTkVector<cGcGraphicsManager::cTkUniformData> maUniformRequests;
    cGcProceduralTextureManager mProceduralTextureManager;
    cTkVector<TkStrongType<int, TkStrongTypeIDs::TkResHandleID>> maShaderHandles;
    cGcFontTable *mpFontData;
    cTkVector<cTk2dTextPreset *> maTextPresets;
    cTkAnimDetailSettingsTable *mapAnimDetailTables[2];
    cGcLogoSequence mLogoSequence;
    uint64_t mu64StartTime;
    std::array<cTkFont, 8> maFonts;
    cTkSmartResHandle mCloudsPipelineRes;
    cTkSmartResHandle mCombinePipelineRes;
    cTkSmartResHandle mColourMaterialRes;
    cTkSmartResHandle mCombineMaterialRes;
    cTkSmartResHandle mScreenshotPipeline;
    cTkSmartResHandle mGenMipmapPipelineRes;
    cTkSmartResHandle mGenMipmapDXT1PipelineRes;
    cTkSmartResHandle mGenMipmapMaterialRes;
    cTkSmartResHandle mPipelineImposterRes;
    cTkSmartResHandle mPipelineImposterNormalsRes;
    cTkSmartResHandle mPipelineImposterOctahedralNormalsRes;
    cTkSmartResHandle mPipelineImposterMasksRes;
    cTkSmartResHandle mPipelineTerrainRes;
    int miGenMipmapGenMipsIndex;
    int miGenMipmapDxt1CompressAllMipsIndex;
    int miGenMipmapDxt5CompressAllMipsIndex;
    int miGenMipmapBc5CompressAllMipsIndex;
    int miGenMipmapBc7CompressAllMipsIndex;
    int miGenMipmapBc7CompressTerrainIndex;
    int miCombineTextureStage;
    int miCombineColourTextureStage;
    int miCombineColourTerrainTextureStage;
    int miCombineMasksTextureStage;
    eAntiAliasing meAntiAliasingMode;
    bool mbApplyMblurHigh;
    bool mbApplyMblurLow;
    bool mbApplyMblur;
    bool mbApplyTaa;
    bool mbApplyTaaCheap;
    bool mbApplyFxaa;
    bool mbApplyDlss;
    bool mbApplyFFXSR;
    bool mbApplyFFXSR2;
    bool mbApplyXess;
    bool mbApplyBicubic;
    bool mbHDROutput;
    bool mbAntiAliasSettingsUnSet;
};

SKYSCRAPER_END