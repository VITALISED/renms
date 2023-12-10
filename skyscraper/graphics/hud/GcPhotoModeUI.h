/**
 * @file GcPhotoModeUI.h
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

#include <graphics/ngui/GcNGuiManager.h>
#include <simulation/environment/GcEnvironment.h>
#include <toolkit/system/TkISystemEventHandler.h>

#include <graphics/gcscreenfilters.meta.h>
#include <user/gcphotomodesettings.meta.h>

SKYSCRAPER_BEGIN

enum ePhotoMode
{
    EPhotoMode_Inactive,
    EPhotoMode_Menu,
    EPhotoMode_MoveCamera,
    EPhotoMode_NumEntries,
};

class PhotoModeControl
{
  public:
    TkID<256> mTitle;
    std::function<bool(void)> mIsValid;

    virtual ~PhotoModeControl();
    virtual void GetValueAsString(cTkFixedString<512, char> *);
    virtual void Reset();
    virtual void Increase();
    virtual void Decrease();
    virtual void EnsureInBounds();
    virtual bool IsValid();
};

struct PhotoModeControlGroup
{
    TkID<256> mTitle;
    cTkVector<PhotoModeControl *> mControls;
};

class cGcPhotoModeUI : public cTkISystemEventHandler
{
  public:
    enum eAdjustRequest
    {
        EAdjustRequest_None,
        EAdjustRequest_Increase,
        EAdjustRequest_Decrease,
        EAdjustRequest_ResetAll,
    };

    enum eHideRequest
    {
        ERequest_None,
        ERequest_HideUI,
        ERequest_ShowUI,
    };

    bool mbInitialised;
    EnvironmentLocation::Enum mePreviousEnvironment;
    cGcPhotoModeSettings mInitialSettings;
    cTkSmartResHandle mTextureHandle;
    cTkSmartResHandle mPipelineRes;
    cGcNGui mCamModeGUI;
    cGcNGui mLocationGUI;
    bool mbShowLocation;
    bool mbShowLocationInstructions;
    cTkVector<PhotoModeControlGroup> mGroups;
    float mfButtonHeldTotalTime;
    float mfButtonPressTimer;
    int miGroup;
    int miOption;
    bool mbNewGroup;
    ePhotoMode meMode;
    ePhotoMode mePreviousMode;
    ePhotoMode meRequestedMode;
    ePhotoMode meModeWhenUnhiding;
    cGcPhotoModeUI::eAdjustRequest meAdjustRequest;
    cGcPhotoModeUI::eHideRequest meHideRequest;
    bool mbIsHidden;
    bool mbWaitingForFrontendToHide;
    cTkBitArray<unsigned int, 1, 32> mPreviousActiveCameraBehaviors;
    float mfAutoHideTimer;
    eScreenFilter meOriginalFarScreenFilter;
    eScreenFilter meOriginalBaseScreenFilter;
    eScreenFilter meOriginalStormScreenFilter;
    float mfOriginalStormFilterStrength;
    cTkFixedString<256, char> mNotificationMessage;
    cTkVector<cTkFixedString<256, char>> maPhotoMessages;
    TkID<256> maFilterNames[82];
    float mfNotificationTimer;
    float mfHideUITime;
    float mfDepthOfFieldDistance;
    float mfDepthOfFieldDistanceSpace;
    float mfHalfFocalPlaneDepth;
    float mfHalfFocalPlaneDepthSpace;
    bool mbShareMenuOpened;
};

SKYSCRAPER_END