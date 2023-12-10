/**
 * @file GcHUDMarker.h
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

#include <graphics/ngui/GcNGuiGraphic.h>
#include <graphics/ngui/GcNGuiManager.h>
#include <simulation/environment/scanning/GcMarkerPoint.h>
#include <toolkit/graphics/2d/ui/objects/Tk2dImage.h>
#include <toolkit/graphics/TkColour.h>
#include <toolkit/maths/numeric/TkSmoothCD.h>
#include <toolkit/utilities/containers/TkClassPool.h>

SKYSCRAPER_BEGIN

class cGcMarkerRenderData
{
  public:
    cTkColour mFillColour;
    cTkColour mBackgroundColour;
    float mfAmount;
    float mfInnerRadius;
    float mfOuterRadius;
};

enum eIcon
{
    EIcon_Scanner,
    EIcon_Scanner_Small,
    EIcon_Binoculars,
    EIcon_NumTypes,
};

class cGcHUDMarker
{
  public:
    struct CompassUpdate
    {
        bool mbHasCompassIcon;
        bool mbIsOnCurrentPlanet;
        bool mbClosestMarkerToCentreCompass;
    };

    enum eHoverState
    {
        EHoverState_Inactive,
        EHoverState_VisibleIn,
        EHoverState_Visible,
        EHoverState_ActiveIn,
        EHoverState_Active,
        EHoverState_StayActive,
        EHoverState_ActiveLocked,
        EHoverState_StayActiveLocked,
        EHoverState_ActiveOut,
        EHoverState_VisibleOut,
        EHoverState_NumStates,
    };

    enum eState
    {
        EState_Inactive,
        EState_Active,
        EState_Deactivating,
    };

    enum eShowLargeState
    {
        EShowLarge_Inactive,
        EShowLarge_In,
        EShowLarge_ShowLarge,
        EShowLarge_Out,
        EShowLarge_NumStates,
    };

    cTkColour mColour;
    cGcMarkerPoint mData;
    cTk2dImageEx mArrowIcon;
    cTkVector2 mCachedCompassPos;
    float mfFade;
    float mfScaleFactor;
    cGcNGui mMarkerIconsNGui;
    cGcNGuiLayer *mpMarkerIconsLayer;
    cGcNGuiLayer *mpMarkerAnimsLayer;
    cGcNGuiGraphic *mpMarkerIconNormal;
    cGcNGuiGraphic *mpMarkerIconSmall;
    cGcNGuiGraphic *mpMarkerIconBinocs;
    cGcNGuiGraphic *mpMarkerIconHighlight;
    cGcNGuiGraphic *mapMarkerIconAnims[3];
    cTkColour mMarkerColour;
    cTkColour mHighlightColour;
    cTkColour maAnimsColours[3];
    float mfMarkerNGuiSize;
    cGcNGui mDistanceTextNGui;
    cGcNGui mCompassDistanceNGui;
    cGcNGuiLayer *mpDistanceTextBottomLayer;
    cGcNGuiLayer *mpDistanceTextTopLayer;
    cGcNGuiLayer *mpDistanceTextCentered;
    cGcNGuiLayer *mpCompassDistanceLayer;
    cGcNGuiLayer *mpCrossplayLayer;
    bool mbDistanceTextShowBottomLayer;
    bool mbDistanceTextShowTopLayer;
    bool mbDistanceTextShowCentered;
    cTkFixedString<128, char> mNGuiDistanceText;
    cTkFixedString<128, char> mNGuiNameText;
    cTkFixedString<128, char> mNGuiCompassDistanceText;
    cGcNetworkConstants::OnlinePlatformType mePlatformIcon;
    cTk2dLayer mCompassLayer;
    cTk2dImageEx maCompassIcons[3];
    cTk2dImageEx mCompassPrimaryIconIndicator;
    bool mbHasCompassIcon;
    bool mbHasLightBeam;
    bool mbDistanceFades;
    bool mbReset;
    cTkSmoothCD<float> mIconSize;
    cTkPhysRelVec3 mFinalPosition;
    cGcHUDMarker::CompassUpdate mCompassUpdate;
    cGcHUDMarker::eHoverState meHoverState;
    float mfHoverTimer;
    float mfShowTagLabelTimer;
    float mfHoverLockTimer;
    float mfHoverLockedTime;
    float mfCreationTime;
    cGcHUDMarker::eState meState;
    eIcon meCurrentIcon;
    bool mbShowMarker;
    bool mbShowLabels;
    float mfStartTime;
    float mfTagRingFade;
    float mfActiveFactor;
    cGcHUDMarker::eShowLargeState meShowLargeState;
    float mfShowLargeTimer;
    cTkSmartResHandle mDefaultIconTexture;
    unsigned int mLineHandle;
    cTkColour mOverwriteColour;
    int miAbandonedFreighterRoom;
    bool mbAbandonedFreighterRoomSet;
    cTkFixedArray<TkStrongType<int, TkStrongTypeIDs::TkResHandleID>, 3> maIconsHandles;
    TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mIconHighlightHandle;
    TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mAnimHandle;
    cTkClassPoolHandle mMarkerHandle;
    cTkClassPoolHandle mDistLabelHandle;
};

SKYSCRAPER_END