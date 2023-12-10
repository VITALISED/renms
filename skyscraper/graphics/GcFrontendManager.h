/**
 * @file GcFrontendManager.h
 * @author VITALISED & Contributors
 * @since 2023-12-08
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

#include <graphics/frontend/components/GcFrontendBackgroundEffect.h>
#include <graphics/frontend/components/GcFrontendTextInput.h>
#include <graphics/frontend/pages/GcFrontendPage.h>
#include <graphics/frontend/pages/GcFrontendPageEnum.h>
#include <graphics/frontend/pages/decorators/GcFrontendPageBasePartPalette.h>
#include <graphics/frontend/pages/decorators/GcFrontendPageCreatureFood.h>
#include <graphics/frontend/pages/decorators/GcFrontendPageCreatureHarvester.h>
#include <graphics/frontend/pages/decorators/GcFrontendPageEggMachine.h>
#include <graphics/frontend/pages/decorators/GcFrontendPageInfoPortal.h>
#include <graphics/frontend/pages/decorators/GcFrontendPageMaintenance.h>
#include <graphics/frontend/pages/decorators/GcFrontendPageManageSettlement.h>
#include <graphics/frontend/pages/decorators/GcFrontendPagePortal.h>
#include <graphics/frontend/pages/decorators/GcFrontendPagePortalDisplayUa.h>
#include <graphics/frontend/pages/decorators/GcFrontendPagePortalRunes.h>
#include <graphics/frontend/pages/decorators/GcFrontendPageRefiner.h>
#include <graphics/frontend/pages/decorators/GcFrontendPageSettlementJudgement.h>
#include <graphics/frontend/pages/decorators/GcFrontendPageSystemHoover.h>
#include <graphics/frontend/pages/decorators/GcFrontendPageVehicleRace.h>
#include <graphics/hud/GcBasePartsMenuUI.h>
#include <graphics/hud/GcBaseUploadUI.h>
#include <graphics/hud/GcPhotoBaseForUploadUI.h>
#include <graphics/hud/GcPhotoModeUI.h>
#include <graphics/ngui/GcNGuiStyledString.h>
#include <networking/GcTextChatManager.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/core/types/TkID.h>
#include <toolkit/graphics/2d/ngui/TkNGuiInput.h>

#include <simulation/customisation/gccustomisationuidata.meta.h>

SKYSCRAPER_BEGIN

enum eShipOperation
{
    EShipOperation_None,
    EShipOperation_Teleport,
    EShipOperation_Full,
};

enum eTeleporterNexusPageState
{
    ETeleporterNexusPageAction_Idle,
    ETeleporterNexusPageAction_MoveToNext,
    ETeleporterNexusPageAction_MoveToPrevious,
    ETeleporterNexusPageAction_ClosePage,
    ETeleporterNexusPageAction_NumTypes,
};

class cGcAmbientModeUI
{
  public:
    cGcNGui mControlsUI;
    bool mbIsActive;
    float mfDeactivationTimer;
    float mfActiveTimer;
};

class cGcReportBaseUI
{};

class cGcFrontendManager
{
  public:
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

    enum eUserState
    {
        EUserState_Ok,
        EUserState_UserLost,
        EUserState_UserLost_Prompting,
        EUserState_UserLost_SigningIn,
        EUserState_UserLost_Checking,
        EUserState_UserLost_Abandon,
        EUserState_PadLost,
        EUserState_PadLost_Prompting,
        EUserState_PadLost_Checking,
    };

    struct MessageBoxData
    {
        bool mbRequestHide;
        bool mbEverVisible;
        bool mbVisible;
        TkID<256> mTitle;
        cTkFixedString<512, char> mMessage;
    };

    struct DialogBoxData : MessageBoxData
    {
        TkID<128> mBoxName;
        TkID<256> mYesLabel;
        TkID<256> mNoLabel;
        bool mbAccepted;
        bool mbDeclined;
        bool mbIsSoft;
        void (*mpOnDialogCloseFunc)(void *, bool, bool);
        void *mpOnCloseData;
    };

    struct sModelLocator
    {
        cTkVector2 mLocatorScreenPos;
        cTkVector2 mIconScreenPos;
        float mAlpha;
        float mIconRadius;
    };

    struct QueuedFrontendPages
    {
        struct PageRequest
        {
            eFrontendPage mePage;
            float mfStartDelay;
            /*cGcInteractionComponent*/ uintptr_t *mpInteraction;
        };

        cGcFrontendManager::QueuedFrontendPages::PageRequest maQueuedPages[3];
        int miPushIndex;
        int miPopIndex;
    };

    struct PageGroup
    {
        cTkVector<std::pair<eFrontendPage, TkID<256>>> mPages;
    };

    struct sDeactivateRequest
    {
        bool mbDeactivate;
        bool mbDismissed;
    };

    cGcFrontendManager::MessageBoxData mMessageBoxData;
    cGcFrontendManager::DialogBoxData mDialogBoxData;
    cGcFrontendTextInput mFrontEndTextInput;
    cGcTextChatInput mTextChatInput;
    cTkNGuiInput mGameGuiInput;
    cTkVector<cGcNGuiStyledString::LayoutInstruction> maTextInstructions;
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
    cTkVector<TkID<128>> maRepairMessagesShown;
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