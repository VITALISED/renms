#pragma once

#include <skyscraper.h>

#include <toolkit/data/TkMetaData.h>
#include <toolkit/graphics/2d/ngui/TkNGuiInput.h>
#include <toolkit/system/TkISystemEventHandler.h>
#include <toolkit/utilities/TkString.h>

SKYSCRAPER_BEGIN

class cGcFrontendManager : public cTkISystemEventHandler
{
    enum eState
    {
        EState_Inactive,
        EState_Booting,
        EState_Wait,
        EState_Activating,
        EState_Active,
        EState_Deactivating,
        EState_ChangePageOut,
        EState_ChangePageIn,
    };

    struct MessageBoxData
    {
        bool mbRequestHide;
        bool mbEverVisible;
        bool mbVisible;
        TkID<256> mTitle;
        cTkFixedString<512, char> mMessage;
    };

    struct DialogBoxData : public cGcFrontendManager::MessageBoxData
    {
        TkID<128> mBoxName;
        TkID<256> mYesLabel;
        TkID<256> mNoLabel;
        bool mbAccepted;
        bool mbDeclined;
        bool mbIsSoft;
        void(__fastcall *mpOnDialogCloseFunc)(void *, bool, bool);
        void *mpOnCloseData;
    };

    cGcFrontendManager::MessageBoxData mMessageBoxData;
    cGcFrontendManager::DialogBoxData mDialogBoxData;
    cGcFrontendTextInput mFrontEndTextInput;
    cGcTextChatInput mTextChatInput;
    cTkNGuiInput mGameGuiInput;
    std::vector<
        cGcNGuiStyledString::LayoutInstruction, TkSTLAllocatorShim<cGcNGuiStyledString::LayoutInstruction, 8, -1>>
        maTextInstructions;
    cGcFrontendBackgroundEffect mBackgroundEffect;
    cGcNGuiLayer mFrontendRoot;
    cGcNGuiLayer mPCOSK;
    eFrontendPage meRequestPage;
    eFrontendPage meNextPage;
    eFrontendPage meFrontendStartPage;
    eFrontendPage mePauseMenuStartPage;
    eFrontendPage meReturnPage;
    cTkAttachmentPtr mpReturnInteractionAttachment;
    bool mbRightHandTransition;
    eShipOperation meAllowedShipOperations;
    bool mabAllowVehicleOperations[7];
    bool mbFadeModel;
    TkID<256> mRequestedPageHint;
    bool mbRequestedPageTransitionRight;
    cGcFrontendPage mPage;
    cGcNGuiLayer *mpPage;
    cGcNGuiLayer *mpRootPickingLayer;
    TkAudioObject mAudioObject;
    cTk2dImageEx mInteractMask;
    int miCursor;
    float mfCursorSizeNormalised;
    bool mbPulseCursor;
    float mfCursorWidth;
    float mfCursorSize;
    bool mbCursorDot;
    cGcNGuiLayer mCursorLayer;
    cGcFrontendManager::eState meState;
    bool mbShowStats;
    cGcFrontendManager::eUserState meUserState;
    bool mbWasInMenus;
    float mfActiveTime;
    float mfContentOffset;
    bool mbCentreCursor;
    int miPageChangeFrameCount;
    cGcFrontendModelRenderer mFrontEndModelRenderer;
    cGcFrontendManager::sModelLocator mFrontendModelLocators[8];
    float mfLocatorsFade;
    cTkVector2 mActiveScreenOffset;
    cTkVector2 mActiveScreenOffsetVel;
    std::vector<TkID<128>, TkSTLAllocatorShim<TkID<128>, 8, -1>> maRepairMessagesShown;
    cGcPhotoModeUI mPhotoModeUI;
    cGcAmbientModeUI mAmbientModeUI;
    cGcReportBaseUI mReportBaseUI;
    cGcPhotoBaseForUploadUI mPhotoBaseForUploadUI;
    cGcBaseUploadUI mBaseUploadUI;
    cGcBasePartsMenuUI mBasePartsMenuUI;
    cGcFrontendPageMaintenance mMaintenancePageUI;
    cGcFrontendPageRefiner mRefinerPageUI;
    cGcFrontendPageSystemHoover mSystemHooverPageUI;
    cGcFrontendPageEggMachine mEggMachinePageUI;
    cGcFrontendPageVehicleRace mVehiclePageUI;
    cGcFrontendPageBasePartPalette mBasePartPaletteUI;
    cGcFrontendPageInfoPortal mInfoPortalUI;
    cGcFrontendPagePortal mPortalUI;
    cGcFrontendPagePortalRunes mPortalRunesUI;
    cGcFrontendPagePortalDisplayUa mPortalUaDisplay;
    cGcFrontendPageCreatureFood mCreatureFoodUI;
    cGcFrontendPageCreatureHarvester mCreatureHarvesterUI;
    cGcFrontendPageManageSettlement mManageSettlementUI;
    cGcFrontendPageSettlementJudgement mSettlementJudgementUI;
    cTkVector2 mParallaxMultiplier;
    cTkVector2 mParallaxMultiplierVel;
    cTkDynamicTexture mUIMaskTexture;
    cGcFrontendManager::QueuedFrontendPages mQueuedFrontendPages;
    cGcFrontendManager::PageGroup mInventoryGroup;
    cGcFrontendManager::PageGroup mPauseGroup;
    cGcFrontendManager::PageGroup mOptionsGroup;
    eTeleporterNexusPageState meNexusTeleporterPageState;
    cGcCustomisationUIData *mpCharacterCustomisationUIData;
    cGcFrontendManager::sDeactivateRequest mDeactivateRequest;
};

SKYSCRAPER_END