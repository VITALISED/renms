/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <skyscraper.h>

#include <application/states/GcApplicationGameModeSelectorState.h>
#include <application/states/GcApplicationState.h>
#include <engine/source/engine/EgTexture.h>
#include <graphics/ngui/GcLayerInteractControl.h>
#include <graphics/ngui/GcNGuiLayer.h>
#include <graphics/ngui/GcNGuiTextSpecial.h>
#include <toolkit/graphics/2d/ngui/TkNGuiInput.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

namespace UGCBaseViewerSelectorPhase
{
typedef WinHttpTask::State::Enum Enum;
}

class cGcApplicationUGCBaseViewerState : public cGcApplicationState
{
    typedef cGcApplicationGameModeSelectorState::DisplayState DisplayState;

    struct State
    {
        TkAudioObject mAudioObject;
        cGcApplicationUGCBaseViewerState::DisplayState mDisplayState;
        int miChosenIndex;
        float mfConfirmationValue;
        bool mbWaitingOnInputGap;
        bool mbPlayingHoldAudio;
    };

    struct IconResources
    {
        cTkSmartResHandle mIconNormal;
        cTkSmartResHandle mIconSurvival;
        cTkSmartResHandle mIconCreative;
        cTkSmartResHandle mIconWarning;
        cTkSmartResHandle mIconPermadeath;
    };

    struct SlotComponents
    {
        cGcNGuiLayer *mpSlot;
        cGcNGuiLayer *mpChoiceRoot;
        cGcNGuiTextSpecial *mpTitle;
        cGcNGuiTextSpecial *mpUserName;
        cGcNGuiText *mpDesc;
        cGcNGuiTextSpecial *mpDesc2;
        cGcNGuiGraphic *mpModeIcon;
        cGcNGuiGraphic *mpScreenshotImage;
        cGcNGuiLayer *mpStarsContainer;
        cGcNGuiGraphic *mpStarsIcons[5];
        cGcNGuiLayer *mpExtraContainer;
        cGcNGuiGraphic *mpExtraIcon;
        ePresetGameMode meMode;
        cTkSmartResHandle mpTextureResourceHandle;
        cEgTextureResource *mpTexResource;
        bool mbEmptySlot;
        cTkFixedString<256, char> mPreviewImageName;
    };

    struct WarningDlgComponents
    {
        cGcNGuiLayer *mpRootLayer;
        cGcNGuiLayer *mpMidSec;
        cGcNGuiLayer *mpLowSec;
        cGcNGuiTextSpecial *mpTitle;
        cGcNGuiTextSpecial *mpHelpContinue;
        cGcNGuiTextSpecial *mpHelpCancel;
        cGcNGuiGraphic *mpIcon;
        cGcNGuiLayer *mpIconFx;
    };

    struct SlotSaveDataState
    {
        int miTimestamp;
    };

    VFT<8> *__vftable;
    cGcNGuiLayer *mpNextPageLayer;
    cGcNGuiLayer *mpPreviousPageLayer;
    cGcNGuiLayer *mpSelectorUIRoot;
    cGcNGuiLayer *mpWarningUIRoot;
    cGcNGuiLayer *mpBackButton;
    cGcNGuiLayer *mpSteamButton;
    cGcNGuiLayer *mpDotsLayer;
    cGcNGuiTextSpecial *mpStatusText;
    float mfStatusTextClearCountdown;
    float mfSlotWidth;
    cGcNGuiLayer *mpHoverLayer;
    cGcApplicationUGCBaseViewerState::IconResources mIconResources;
    std::array<cGcApplicationUGCBaseViewerState::SlotComponents, 5> mSlotComponents;
    cGcApplicationUGCBaseViewerState::WarningDlgComponents mWarningDlgComponents;
    std::array<cGcApplicationUGCBaseViewerState::SlotSaveDataState, 3> mSlotSaveStates;
    cGcAsyncLoadOps mAsyncLoadOps;
    cGcLayerInteractControl *mpLayerInteractControl;
    cTkNGuiInput mSelectorGuiInput;
    bool mbDebounceInitialInput;
    UGCBaseViewerSelectorPhase::Enum mPhase;
    cGcApplicationUGCBaseViewerState::State mState;
    float mfAppearFade;
    float mfTimeFx;
    int miPrepareCount;
    bool mbCenterCursor;
    unsigned int miLastUGCSubscriptionsCount;
    unsigned int miUGCPage;
    cTkVector<unsigned int> mUGCSubscriptionIdLookups;
};

SKYSCRAPER_END