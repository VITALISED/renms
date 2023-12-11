/**
 * @file GcWFCModuleSetNGuiWindow.h
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

#include <gamestate/GcPersistentInteractionsManager.h>
#include <graphics/ngui/windows/GcNGuiWindow.h>
#include <simulation/solarsystem/buildings/wfcbuildings/GcModuleSet.h>
#include <toolkit/graphics/utilities/TkModelResourceRenderer.h>

#include <simulation/environment/wfcbuildings/decoration/gcwfcdecorationtheme.meta.h>
#include <toolkit/ngui/tknguitextstyle.meta.h>

SKYSCRAPER_BEGIN

enum eWFCBuildingStage
{
    EWFCBuildingStage_Layout,
    EWFCBuildingStage_Level0,
    EWFCBuildingStage_Level1,
    EWFCBuildingStage_HigherLevels,
    EWFCBuildingStage_Decoration,
    EWFCBuildingStage_NumTypes,
};

enum EWFCTestMode
{
    eWFCTestMode_Custom,
    eWFCTestMode_Building,
    eWFCTestMode_Preset,
};

class cGcWFCModuleSetNGuiWindow;

class cGcModulePrototypeElement
{
  public:
    const cGcWFCModulePrototype *mModulePrototype;
    cGcWFCScene *mGeometry;
    TkStrongType<int, TkStrongTypeIDs::cTkNGuiFontHandleID> mImageHandle;
    cTkModelResourceRenderer mRenderer;
    cGcWFCModuleSetNGuiWindow *mpWindow;
    TkHandle mModelNode;
    int miRemainingRenders;
    bool mbRendererConstructed;
};

struct sWFCBuildingPart
{
    TkID<128> mPartID;
    cTkMatrix34 mTransform;
    float mfScale;
    eWFCBuildingStage meStage;
    eWFCDecorationTheme meTheme;
    int miSpawnStage;
    const sFreighterRoom *mpFreighterRoom;
    GcPersistencyHandle mPersistencyHandle;
};

class cGcWFCModuleSetNGuiWindow : public cGcNGuiWindow
{
  public:
    bool mbRequestSpawnMap;
    bool mbRequestShowMap;
    bool mbRequestReloadModuleSet;
    float mfPreviewRotationAngle;
    cGcModuleSet *mpModuleSet;
    cGcWFCModuleSet *mpMetadataModuleSet;
    cGcMap *mpMap;
    cTkVector<cGcModulePrototypeElement *> mapModulePrototypeElements;
    cTkAABB mBlockBoundingBox;
    TkHandle mSceneNode;
    TkHandle mModelViewerNode;
    cTkAABB mModelViewerBoundingBox;
    cTkVector<sWFCBuildingPart> mParts;
    int miPartsAdded;
    int miSelectedModule;
    cTkNGuiTextStyle mTextStyleX;
    cTkNGuiTextStyle mTextStyleY;
    cTkNGuiTextStyle mTextStyleZ;
    cTkNGuiTextStyle mTextStyle;
    cTkNGuiTextStyle mTextStyleExcludedModule;
    cTkIntTuple3<int> mMapSize;
    bool mbCreateSymmetricMap;
    bool mbCreateCoherentMap;
    bool mbDecorate;
    EWFCTestMode meTestMode;
    int miPresetIndex;
    bool mbHideTopLevel;
    robin_hood::detail::Table<true, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>
        mGroups;
    cTkVector<std::pair<TkID<128>, cTkSmartResHandle>> mPartOverrides;
    cTkFixedString<128, char> macStatus;
    cTkFixedString<128, char> macDebugFilename;
};

SKYSCRAPER_END