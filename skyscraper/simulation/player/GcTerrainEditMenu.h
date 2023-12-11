/**
 * @file GcTerrainEditMenu.h
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

#include <simulation/player/GcQuickMenuTypes.h>
#include <simulation/projectiles/GcTerrainEditorBeam.h>
#include <toolkit/graphics/utilities/TkModelResourceRenderer.h>
#include <toolkit/voxel/manager/TkVoxel.h>

SKYSCRAPER_BEGIN

class cGcTerrainEditMenu : public cGcQuickMenuState
{
  public:
    struct MenuGroup
    {
        TkID<256> mGroupName;
        int miCurrentOption;
        int miSize;
    };

    enum eMenuGroup
    {
        EMenuGroup_Materials,
        EMenuGroup_Shapes,
        EMenuGroup_NumGroups,
    };

    cGcTerrainEditMenu::MenuGroup maMenuGroup[2];
    cGcTerrainEditMenu::eMenuGroup meCurrentGroup;
    cTkSmartResHandle mTerrainBallMaterial[5];
    cTkModelResourceRenderer mTerrainEditBallRenderer[5];
    bool mbRenderRequested[5];
    cTkSmartResHandle maTerrainBalls[5];
    TkHandle mTerrainBallsGroup;
    cTkSmartResHandle maShapeIcons[2];
    eVoxelType meTerrainType;
    eTerrainEditShape meEditShape;
    bool mbWasChangingMaterial;
};

SKYSCRAPER_END