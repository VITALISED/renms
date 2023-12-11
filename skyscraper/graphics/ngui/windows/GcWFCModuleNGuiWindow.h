/**
 * @file GcWFCModuleNGuiWindow.h
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
#include <simulation/solarsystem/buildings/wfcbuildings/GcModuleSet.h>
#include <toolkit/graphics/utilities/TkModelResourceRenderer.h>

#include <toolkit/ngui/tknguitextstyle.meta.h>

SKYSCRAPER_BEGIN

class cGcWFCModuleNGuiWindow;

enum eBlockDirection
{
    EBlockDirection_Left,
    EBlockDirection_Down,
    EBlockDirection_Back,
    EBlockDirection_Right,
    EBlockDirection_Up,
    EBlockDirection_Forward,
};

class cGcPossibleNeighbourElement
{
  public:
    const cGcModule *mModule;
    const eBlockDirection meDirection;
    TkStrongType<int, TkStrongTypeIDs::cTkNGuiFontHandleID> mImageHandle;
    cTkModelResourceRenderer mRenderer;
    cGcWFCModuleNGuiWindow *mpWFCModuleGuiWindow;
    TkHandle mModelNode;
    int miRemainingRenders;
    bool mbRendererConstructed;
};

class cGcWFCModuleNGuiWindow : public cGcNGuiWindow
{
  public:
    bool mbRequestSetup;
    bool mbAddMargin;
    cGcModuleSet *mpModuleSet;
    cGcWFCModuleSet *mpMetadataModuleSet;
    int miCurrentModulePrototypeIndex;
    cGcWFCModulePrototype *mpCurrentModulePrototype;
    cTkAABB mBlockBoundingBox;
    cTkFixedString<128, char> mIndexInfoText;
    bool mabPossibleNeighboursCategoryMaximised[6];
    TkHandle mSceneNode;
    cTkVector<cGcPossibleNeighbourElement *> mapPossibleNeighbourGuiElements[6];
    cTkNGuiTextStyle mModuleNameTextStyle;
    cTkVector<std::pair<TkID<128>, cTkSmartResHandle>> *mpPartOverrides;
};

SKYSCRAPER_END