/**
 * @file GcNGuiSceneView.h
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
#include <toolkit/core/types/TkHandle.h>

SKYSCRAPER_BEGIN

class cGcNGuiSceneView : public cGcNGuiWindow
{
  public:
    enum eSceneViewActions
    {
        ESceneViewAction_None,
        ESceneViewAction_Browse,
        ESceneViewAction_Load,
        ESceneViewAction_Create,
        ESceneViewAction_SaveAll,
        ESceneViewAction_SaveSettings,
        ESceneViewAction_SaveScene,
        ESceneViewAction_SaveSolarSystem,
        ESceneViewAction_SavePlanetScene,
        ESceneViewAction_SetStartLocation,
    };

    float mfScale;
    bool mbShowGrid;
    TkHandle maGridPoints[32][32];
    TkHandle mBaseNode;
    cGcNGuiSceneView::eSceneViewActions meNextAction;
    TkHandle mHighlightNode;
};

SKYSCRAPER_END