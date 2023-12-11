/**
 * @file GcNGuiModelViewer.h
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

#include <graphics/ngui/windows/GcNGuiWindow.h>
#include <toolkit/graphics/2d/ngui/TkNGuiCallback.h>
#include <toolkit/graphics/utilities/TkModelResourceRenderer.h>

SKYSCRAPER_BEGIN

class cGcNGuiModelViewer : public cGcNGuiWindow
{
  public:
    enum eLoadState
    {
        Ready,
        Generating,
        Loaded,
    };
    bool mbRenderViewVariantsButton;
    bool mbViewActive;
    bool mbViewMouseActive;
    bool mbViewMouse2Active;
    bool mbViewMouse3Active;
    int miPrevMouseX;
    int miPrevMouseY;
    cTkColour mBackgroundColour;
    cTkMatrix34 mModelMatrix;
    cTkModelResourceRenderer mRenderer;
    TkStrongType<int, TkStrongTypeIDs::cTkNGuiFontHandleID> mImageHandle;
    cTkNGuiCallbackData mAnimationCallback;
    TkID<256> mTextureNameHint;
    cTkFixedString<1024, char> mProcFilters;
    bool mbSaveImage;
    uint8_t meButtonPressed[4];
    int miRequestFlags;
    cTkSmartResHandle mRequestFromRes;
    TkHandle mRequestFromNode;
    cTkFixedString<256, char> mModelFilename;
    cGcNGuiModelViewer::eLoadState meLoadState;
    cTkSmartResHandle mLoadedModel;
    bool mbRequestResourceRefresh;
    bool mbUseCustomisationData;
    bool mbSelectedNewResource;
};

class cGcModelViewerCustomisationWindow : public cGcNGuiWindow
{};

SKYSCRAPER_END