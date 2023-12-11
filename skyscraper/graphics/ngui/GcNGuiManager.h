/**
 * @file GcNGuiManager.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
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

#include <graphics/ngui/GcNGuiLayer.h>
#include <graphics/ngui/windows/GcBaseBuildingObjectNGuiWindow.h>
#include <graphics/ngui/windows/GcNGuiCreatureGenerationViewer.h>
#include <graphics/ngui/windows/GcNGuiEffectViewer.h>
#include <graphics/ngui/windows/GcNGuiFileBrowser.h>
#include <graphics/ngui/windows/GcNGuiGameView.h>
#include <graphics/ngui/windows/GcNGuiGreenScreen.h>
#include <graphics/ngui/windows/GcNGuiModelInfo.h>
#include <graphics/ngui/windows/GcNGuiModelViewer.h>
#include <graphics/ngui/windows/GcNGuiNodeGraphViewer.h>
#include <graphics/ngui/windows/GcNGuiProceduralModelAllVariantsViewer.h>
#include <graphics/ngui/windows/GcNGuiProceduralModelViewer.h>
#include <graphics/ngui/windows/GcNGuiProceduralTextureViewer.h>
#include <graphics/ngui/windows/GcNGuiSceneView.h>
#include <graphics/ngui/windows/GcSettlementStateNGuiWindow.h>
#include <graphics/ngui/windows/GcWFCModuleNGuiWindow.h>
#include <graphics/ngui/windows/GcWFCModuleSetNGuiWindow.h>
#include <toolkit/graphics/2d/ui/layers/Tk3dLayer.h>
#include <toolkit/graphics/2d/ui/objects/Tk2dImage.h>

SKYSCRAPER_BEGIN

class cGcNGuiProfiler;

class cGcNGui
{
  public:
    cGcNGuiLayer mRoot;
    cTkNGuiInput mInput;
    bool mbUseInput;
    float mfPixelRatio;
    bool mbFullscreen;
    cTkVector2 mCustomSize;
    bool mbHasCustomSize;
    bool mbIsInWorld;
    cTk3dLayer mTk3dLayer;
    cTk2dImage mTk2dImage;
};

class cGcNGuiManager
{
  public:
    struct ColourPreset
    {
        cTkFixedString<256, char> macName;
        cTkColour mCurrentLive;
        cTkColour mCurrent;
        cTkColour mBase;
    };

    cTkVector<cGcNGuiManager::ColourPreset> maPresetColours;
    cTkNGuiElementID mGuiEditor;
    cTkNGuiElementID mGuiScene;
    cTkNGuiElementID mGuiStyles;
    cTkNGuiElementID mGame;
    cTkNGuiElementID mEdit;
    cTkNGuiElementID mMetadata;
    cTkNGuiInput mNullInput;
    cTkNGuiInput mGuiInput;
    /*NVGcontext*/ uintptr_t *mpContext;
    bool mbEditMode;
    cGcNGuiFileBrowser *mpFileBrowser;
    cGcNGuiModelViewer *mpModelViewer;
    cGcNGuiModelInfo *mpModelInfo;
    cGcModelViewerCustomisationWindow *mpModelCustomisation;
    cGcNGuiProceduralModelViewer *mpProceduralModelViewer;
    cGcNGuiProceduralTextureViewer *mpProceduralTextureViewer;
    cGcNGuiProfiler *mpProfiler;
    cGcNGuiGameView *mpGameView;
    cGcNGuiSceneView *mpSceneView;
    cGcNGuiEffectViewer *mpEffectViewer;
    cGcNGuiNodeGraphViewer *mpNodeGraphViewer;
    cGcNGuiCreatureGenerationViewer *mpCreatureGenerationViewer;
    cGcWFCModuleSetNGuiWindow *mpWFCModuleSetWindow;
    cGcWFCModuleNGuiWindow *mpWFCModuleWindow;
    cGcSettlementStateNGuiWindow *mpSettlementStateWindow;
    cGcBaseBuildingObjectNGuiWindow *mpBaseBuildingObjectViewerWindow;
    cGcNGuiGreenscreen *mpGreenScreenWindow;
    cGcNGuiProceduralModelAllVariantsViewer *mpProceduralModelAllVariantsViewer;
    cTkVector<cGcNGuiWindow *> mapNGuiWindows;
    eAltMode meLastKnownAltMode;
    bool mbRenderFramesAllowed;
    bool mbFrameHasBegun;
    int miDumpVertexCounter;
    uint64_t mMaxVertCountLocation[2];
    int miMaxVertCount;
};

SKYSCRAPER_END