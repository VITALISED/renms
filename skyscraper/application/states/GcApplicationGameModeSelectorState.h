#pragma once

#include <skyscraper.h>
#include <application/states/GcApplicationState.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <graphics/ngui/GcNGuiLayer.h>
#include <graphics/ngui/GcNGuiTextSpecial.h>
#include <graphics/ngui/GcNGuiText.h>
#include <metadata/user/gcdifficultypresettype.meta.h>
#include <metadata/user/gcdifficultysettingsdata.meta.h>
#include <metadata/gamestate/gcgamemode.meta.h>

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

class cGcApplicationGameModeSelectorState : public cGcApplicationState
{
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
    struct EnumIconResources/*<enum eModeSelectPreset,7>*/
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
    cGcApplicationGameModeSelectorState::EnumIconResources<ePresetGameMode,7> mSmallGameModeIcons;
    cGcApplicationGameModeSelectorState::EnumIconResources<eModeSelectPreset,7> mModeSelectPresetIcons;
    cGcApplicationGameModeSelectorState::EnumIconResources<eModeSelectPreset,7> mModeSelectPresetBackgrounds;
    cGcApplicationGameModeSelectorState::EnumIconResources<eModeSelectPreset,7> mModeSelectPresetDesaturatedBackgrounds;
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
    cTkFixedString<128,char> msMPHostName;
    cTkFixedString<256,char> msMPOtherPlayers;
    cTkFixedString<64,char> msMPGameMode;
    bool mbSkippedStartScreen;
    bool mbShowingOKCancelDialog;
    std::function<void __cdecl(bool,bool)> mOnCancelDialogClosedCallbackFn;
    bool mbVRModeSelected;
    float mfAutoJoinDelay;
    TkStrongType<int,TkStrongTypeIDs::TkResHandleID> mPipelineResource;
    cTkVector<bool> maPreviousPipelineStageState;
    std::array<cGcApplicationGameModeSelectorState::SlotComponents,5> mSaveSlotComponents;
    std::array<cGcApplicationGameModeSelectorState::SlotComponents,7> mModeSlotComponents;
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
};

SKYSCRAPER_END