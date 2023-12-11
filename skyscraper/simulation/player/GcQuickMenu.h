/**
 * @file GcQuickMenu.h
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

#include <simulation/player/GcBuildMenu.h>
#include <simulation/player/GcGalaxyPathMenu.h>
#include <simulation/player/GcQuickActionMenu.h>
#include <simulation/player/GcQuickMenuTypes.h>
#include <simulation/player/GcTerrainEditMenu.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cGcQuickMenu
{
  public:
    int miUpdateIndex;
    int miRenderIndex;
    std::array<QuickMenuRenderState, 2> maRenderStates;
    bool mbOpenQuickMenu;
    bool mbActivatedThisFrame;
    eQuickMenuState meQuickMenuState;
    cGcQuickActionMenu mQuickActionMenu;
    cGcBuildMenu mBuildMenu;
    cGcTerrainEditMenu mTerrainMenu;
    cGcGalaxyPathMenu mGalaxyPathMenu;
    int miUpdateCount;
    bool mbRenderActive;
    bool mbRenderStartHidden;
    AnimateItems mItemsAnimation;
    AnimateItems mNextItemsAnimation;
    AnimateItems mEnterMenuAnimation;
    AnimateItems mUpArrowAnimation;
    AnimateItems mLeftArrowAnimation;
    AnimateItems mRightArrowAnimation;
    cTkSmartResHandle maHotKeyIcons[10];
    float mfMenuClosedTime;
};

SKYSCRAPER_END