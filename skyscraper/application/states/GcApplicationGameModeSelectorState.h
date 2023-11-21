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

#include <application/states/GcApplicationState.h>
#include <atlas/WinHttpTask.h>
#include <gamestate/GcGameStatePersistence.h>
#include <graphics/ngui/GcLayerInteractControl.h>
#include <graphics/ngui/GcNGuiGraphic.h>
#include <graphics/ngui/GcNGuiLayer.h>
#include <graphics/ngui/GcNGuiText.h>
#include <graphics/ngui/GcNGuiTextSpecial.h>
#include <system/GcModManager.h>
#include <toolkit/graphics/2d/ngui/TkNGuiInput.h>
#include <toolkit/maths/numeric/TkSmoothCD.h>
#include <toolkit/system/pc/TkStoragePersistent.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <gamestate/gcgamemode.meta.h>
#include <user/gcdifficultypresettype.meta.h>
#include <user/gcdifficultysettingsdata.meta.h>

SKYSCRAPER_BEGIN

enum eModeSelectPreset
{
    EModeSelectPreset_Unspecified,
    EModeSelectPreset_Normal,
    EModeSelectPreset_Creative,
    EModeSelectPreset_Relaxed,
    EModeSelectPreset_Survival,
    EModeSelectPreset_Custom,
    EModeSelectPreset_Seasonal,
    EModeSelectPreset_NumTypes,
};

namespace ModeSelectorPhase
{
typedef WinHttpTask::State::Enum Enum;
}

class cGcApplicationGameModeSelectorState : public cGcApplicationState
{
  public:
    enum DisplayState
    {
        EHostJoinSelection,
        ESlotSelection,
        EModeSelection,
        ECustomDifficulty,
        EDeletionWarning,
        EMultiplayerFriends,
        EManageCloudSaves,
        EOptions,
        ECredits,
        ERemapControls,
        EManageMods,
        EManageModsSaves,
    };

    enum CloudSaveUpdateState
    {
        eShowingInfo,
        eUploadingData,
        eDownloadingData,
        eConfirmOverwriting,
        eShowingResult,
    };

    enum MultiplayerState
    {
        ENone,
        EFriendLobby,
        ERandom,
    };

    template <typename T, unsigned int liCount>
    struct EnumIconResources
    {
        cTkSmartResHandle mResources[liCount];
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

    struct State
    {
        cGcApplicationGameModeSelectorState::DisplayState mDisplayState;
        cGcApplicationGameModeSelectorState::MultiplayerState mMultplayerState;
        int miChosenIndex;
        int miFriendsPage;
        int miModsPage;
        int miModsSavesManagerPage;
        float mfConfirmationValue;
        bool mbWaitingOnInputGap;
        bool mbPlayingHoldAudio;
    };

    struct SlotComponents
    {
        cGcNGuiLayer *mpSlot;
        cGcNGuiLayer *mpChoiceRoot;
        cGcNGuiGraphic *mpIcon;
        cGcNGuiTextSpecial *mpModeTitle;
        cGcNGuiTextSpecial *mpSubtitle;
        cGcNGuiGraphic *mpBackground;
        cGcNGuiGraphic *mpBackgroundDesaturated;
        cGcNGuiGraphic *mpBackgroundLocked;
        cGcNGuiLayer *mpHighlightLayer;
        cGcNGuiLayer *mpSeasonLayer;
        cGcNGuiTextSpecial *mpSeasonHeaderText;
        cGcNGuiTextSpecial *mpSeasonTimeText;
        cGcNGuiGraphic *mpSeasonTimeBackground;
        cGcNGuiGraphic *mpSeasonTimeLowBackground;
        cGcNGuiTextSpecial *mpSeasonDescText;
        cGcNGuiTextSpecial *mpSeasonTitleText;
        cGcNGuiText *mpSlotTitle;
        cGcNGuiLayer *mpTwoLineSlot;
        cGcNGuiText *mpTwoLineSlotTitle;
        cGcNGuiText *mpSlotSummary;
        cGcNGuiText *mpGameModeFinger;
        cGcNGuiLayer *mpLayerSaveContainer;
        cGcNGuiLayer *mpLayerSaveBlank;
        cGcNGuiLayer *mpLayerSaveOK;
        cGcNGuiTextSpecial *mpSaveTimeText;
        cGcNGuiLayer *mpLayerPlayContainer;
        cGcNGuiLayer *mpLayerPlayBlank;
        cGcNGuiLayer *mpLayerPlayOK;
        cGcNGuiTextSpecial *mpPlayTimeText;
        cGcNGuiLayer *mpDisabled;
        cTkSmoothCD<float> mfHighlightAlpha;
    };

    cGcNGuiLayer *mpSelectorUIRoot;
    cGcNGuiLayer *mpDeletionWarningUIRoot;
    cGcNGuiLayer *mpSlotUIRoot;
    cGcNGuiLayer *mpModeUIRoot;
    cGcNGuiLayer *mpMultiplayerUIRoot;
    cGcNGuiLayer *mpCloudSavesUIRoot;
    cGcNGuiLayer *mpStartUIRoot;
    cGcNGuiLayer *mpVRModeButton;
    cGcNGuiLayer *mpPCOSK;
    cGcNGuiLayer *mpError;
    cGcNGuiLayer *mpPatchNotesBox;
    cGcNGuiLayer *mpOKCancelDialog;
    cGcNGuiLayer *mpModManagerUIRoot;
    cGcNGuiLayer *mpModSaveManagerUIRoot;
    cTkVector<bool> mCustomSavesDeletionSelectionState;
    cGcNGuiLayer *mpCustomDifficultyUIRoot;
    cGcNGuiLayer *mpOptionsUIRoot;
    cGcNGuiLayer *mpCreditsUIRoot;
    cGcNGuiLayer *mpRemapControlsUIRoot;
    cGcNGuiTextSpecial *mpStatusText;
    float mfStatusTextClearCountdown;
    float mfSlotWidth;
    cGcNGuiLayer *mpHoverLayer;
    cGcApplicationGameModeSelectorState::EnumIconResources<ePresetGameMode, 7> mSmallGameModeIcons;
    cGcApplicationGameModeSelectorState::EnumIconResources<eModeSelectPreset, 7> mModeSelectPresetIcons;
    cGcApplicationGameModeSelectorState::EnumIconResources<eModeSelectPreset, 7> mModeSelectPresetBackgrounds;
    cGcApplicationGameModeSelectorState::EnumIconResources<eModeSelectPreset, 7>
        mModeSelectPresetDesaturatedBackgrounds;
    cTkSmartResHandle mIconWarning;
    cGcApplicationGameModeSelectorState::WarningDlgComponents mWarningDlgComponents;
    cGcAsyncLoadOps mAsyncLoadOps;
    cGcLayerInteractControl *mpLayerInteractControl;
    cTkNGuiInput mSelectorGuiInput;
    ModeSelectorPhase::Enum mPhase;
    cGcApplicationGameModeSelectorState::State mState;
    float mfAppearFade;
    float mfTimeFx;
    float mfNotifyTimer;
    unsigned int muSelectedPlayerSlot;
    bool mbSelectedEmptySlot;
    ePresetGameMode meSelectedGameMode;
    unsigned int muOccupiedSlots;
    eDifficultyPresetType meSelectedDifficultyPreset;
    cGcDifficultySettingsData mSelectedDifficultySettings;
    int miPrepareCount;
    bool mbDownloadedSeasonalData_REMOVEME;
    bool mbModeUISetupRequired;
    bool mbCenterCursor;
    ePresetGameMode mUGCBaseModeToLoad;
    bool mbLoadDirectlyToBase;
    int miSyncStateTimeout;
    bool mbCompletedBefore;
    float mfCursorSizeNormalised;
    bool mbCursorHoverActive;
    cTkFixedString<128, char> msMPHostName;
    cTkFixedString<256, char> msMPOtherPlayers;
    cTkFixedString<64, char> msMPGameMode;
    bool mbSkippedStartScreen;
    bool mbShowingOKCancelDialog;
    std::function<void __cdecl(bool, bool)> mOnCancelDialogClosedCallbackFn;
    bool mbVRModeSelected;
    float mfAutoJoinDelay;
    TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mPipelineResource;
    cTkVector<bool> maPreviousPipelineStageState;
    std::array<cGcApplicationGameModeSelectorState::SlotComponents, 5> mSaveSlotComponents;
    std::array<cGcApplicationGameModeSelectorState::SlotComponents, 7> mModeSlotComponents;
    cTkVector<GcGameStatePersistence::StorageSlotInformation> mSlotSaveStates;
    ScrollBarState mSaveSlotsScrollBarState;
    int miSlotsScrollStartIndex;
    cTkVector<cGcModManager::ModInfo> mLoadedModsInfo;
    cTkStoragePersistent::LowSpaceWarningData mLowSpaceWarningData;
    float mfLowSpaceSkipDelay;
    bool mbFirstBoot;
    char *mpSaveDirectory;
    bool mbWaitingOnConsoleOSK;
    bool mbCanUploadCloudSave;
    bool mbCanDownloadCloudSave;
    bool mbCloudSaveResult;
    float mfCloudResultTimer;
    cGcApplicationGameModeSelectorState::DisplayState meScreenToReturnToFromOptionsScreen;
    cGcApplicationGameModeSelectorState::CloudSaveUpdateState meCloudSaveUpdateState;

    ~cGcApplicationGameModeSelectorState();
    void Construct();
    void Prepare(cTkFSMState *, const void *);
    void Update(float);
    void Event(unsigned int, const void *);
    void Release(cTkFSMState *, const void *);
    void Destruct();
    void Render(EgRenderParity::List);
};

SKYSCRAPER_END