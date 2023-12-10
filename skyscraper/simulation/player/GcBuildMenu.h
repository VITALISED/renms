/**
 * @file GcBuildMenu.h
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

#include <basebuilding/GcBaseBuildingObject.h>
#include <basebuilding/GcBaseBuildingPlaceholder.h>
#include <graphics/ngui/GcNGuiManager.h>
#include <simulation/player/GcQuickMenuTypes.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/maths/numeric/TkSmoothCD.h>

#include <gamestate/basebuilding/gcbasebuildingmode.meta.h>
#include <gamestate/basebuilding/gcbuildmenuoption.meta.h>

SKYSCRAPER_BEGIN

class cGcBuildMenu : public cGcQuickMenuState
{
  public:
    enum eSelectModeStage
    {
        ESelectModeStage_Root,
        ESelectModeStage_Colour,
        ESelectModeStage_Material,
    };

    enum eSelectModeOption
    {
        ESelectModeOption_BrowseMode,
        ESelectModeOption_Pickup,
        ESelectModeOption_Duplicate,
        ESelectModeOption_Delete,
        ESelectModeOption_Colour,
        ESelectModeOption_Material,
        ESelectModeOption_ReportBase,
    };

    struct sBuildOptionsGui
    {
        struct sBuildOptionsRenderData
        {
            TkID<128> mCyclePartId;
            cTkVector2 mScreenPos;
            cTkBitArray<unsigned int, 1, 32> mLastActionWasError;
            float mafLastInputTime[16];
            float mfErrorAlpha;
            bool mbTransitioningToOrFromFrontendMode;
            bool mbRenderMenu;
        };

        struct sRotation
        {
            TkAudioObject mAudioObject;
            float mfStartTime;
            float mfStopTime;
            float mfPreviousInput;
            cGcBaseBuildingPlayerPlacement::RotationAxis meCurrentRotationAxis;
            bool mbCameraSpace;
            bool mbHasChangedAxis;
            bool mbPlayingAudio;
        };

        struct sScale
        {
            TkAudioObject mAudioObject;
            float mfStartTime;
            float mfStopTime;
            bool mbPlayingAudio;
        };

        cGcBuildMenu::sBuildOptionsGui::sBuildOptionsRenderData mRender;
        cGcNGui mGui;
        cTkFixedString<256, char> mPlacementErrorString;
        cTkFixedString<256, char> mInvalidPlacementString;
        float mfLastValidPlacementTime;
        cTkFixedString<128, char> maActionText[16];
        cTkSmoothCD<cTkVector2> mSmoothScreenPos;
        cTkSmoothCD<float> mErrorAlpha;
        TkID<128> mPreviousPartBeingPlaced;
        TkID<128> mCyclePartId;
        TkID<128> mHighlightedPart;
        cTkVector3 mWorldPos;
        cTkVector2 mScreenPos;
        TkHandle mSelectionTarget;
        float mfButtonWidth;
        float mfSpacerWidth;
        float mafLastInputTime[16];
        cGcBuildMenu::sBuildOptionsGui::sRotation mRotation;
        cGcBuildMenu::sBuildOptionsGui::sScale mScale;
        cTkBitArray<unsigned int, true, 32> mVisibleOptions;
        cTkBitArray<unsigned int, true, 32> mEnabledOptions;
        cTkBitArray<unsigned int, true, 32> mToggledOptions;
        cTkBitArray<unsigned int, true, 32> mShowInputIcon;
        cTkBitArray<unsigned int, true, 32> mLastActionWasError;
        float mfTimeSinceMostRecentActionWithDescription;
        eBuildMenuOption meMostRecentActionWithDescription;
        eBuildMenuOption meHighlightedOption;
        eBuildMenuOption meSelectedOption;
        eBaseBuildingMode mePreviousMode;
        uint8_t mu8PaletteIndex;
        uint8_t mu8MaterialIndex;
        bool mbLastFrameWasViewingPalette;
        bool mbShowColourSwatch;
        bool mbShowMaterialSwatch;
        bool mbShowCursor;
    };

    struct BuildGroups
    {
        enum eGroupNodeType
        {
            EGroupNodeType_BuildGroup,
            EGroupNodeType_BuildObject,
            EGroupNodeType_BuildColour,
            EGroupNodeType_BuildMaterial,
        };

        struct GroupNode
        {

            cTkVector<int> mChildren;
            TkID<128> mGroupName;
            uint8_t miVersion;
            const cGcBuildMenu::BuildGroups::eGroupNodeType meType;
            int miParent;
            uint8_t miLastSelectedChild;
            uint8_t miAvailableChildren;
        };

        std::unordered_map<uint64_t, int> mGroupIndicies;
        cTkVector<cGcBuildMenu::BuildGroups::GroupNode> mGroupNodes;
        int miCurrentSelectedGroup;
    };

    TkID<128> mBreadcrumbID;
    bool mbFirstUpdateAfterOpening;
    bool mbInputThisFrame;
    bool mbActivateRequested;
    float mfLastClosedTime;
    cGcBuildMenu::eSelectModeStage meSelectionModeStage;
    cGcBuildMenu::eSelectModeOption meSelectionModeOption;
    cGcBuildMenu::sBuildOptionsGui mBuildOptionsGui;
    cTkVector<BaseBuildingObjectTemplate const *> maAvailableWires;
    cGcBuildMenu::BuildGroups mBuildingGroups;
};

SKYSCRAPER_END