#pragma once

#include <skyscraper.h>

#include <graphics/frontend/components/GcFrontendTextInput.h>
#include <graphics/ngui/GcNGuiLayer.h>
#include <graphics/ngui/GcNGuiStyledString.h>
#include <networking/GcTextChatManager.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/data/TkMetaData.h>
#include <toolkit/graphics/2d/ngui/TkNGuiInput.h>
#include <toolkit/system/TkISystemEventHandler.h>
#include <toolkit/utilities/TkString.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cGcFrontendBackgroundEffect
{
    cGcNGuiLayer *mpLayer;
    cTkVector2 mMousePos;
};

// I hate this with a passion, WHY ISNT THIS METADATA HG!!!!!!!!!!!!
enum eFrontendPage
{
    EFrontendPage_None = 0xFFFFFFFF,
    EFrontendPage_Suit,
    EFrontendPage_Ship,
    EFrontendPage_Vehicle,
    EFrontendPage_Freighter,
    EFrontendPage_Weapon,
    EFrontendPage_Discovery,
    EFrontendPage_Journey,
    EFrontendPage_MissionLog,
    EFrontendPage_Wiki,
    EFrontendPage_Catalogue,
    EFrontendPage_InfoPortal,
    EFrontendPage_Season,
    EFrontendPage_Options,
    EFrontendPage_Switcher,
    EFrontendPage_Controls,
    EFrontendPage_Network,
    EFrontendPage_NetworkPlayers,
    EFrontendPage_NetworkManageFriends,
    EFrontendPage_NetworkManageBlocked,
    EFrontendPage_Difficulty,
    EFrontendPage_Credits,
    EFrontendPage_Redeem,
    EFrontendPage_Interact,
    EFrontendPage_InteractDialog,
    EFrontendPage_InteractConsole,
    EFrontendPage_InteractShip,
    EFrontendPage_Trade,
    EFrontendPage_TechTrade,
    EFrontendPage_BuildingTrade,
    EFrontendPage_SpecialsTrade,
    EFrontendPage_MissionList,
    EFrontendPage_MissionHandInList,
    EFrontendPage_MissionRenounce,
    EFrontendPage_MissionDescription,
    EFrontendPage_BuyScreen,
    EFrontendPage_CompareScreen,
    EFrontendPage_DisplayTech,
    EFrontendPage_DisplayProduct,
    EFrontendPage_DisplayPatchNotes,
    EFrontendPage_FreighterTransferScreen,
    EFrontendPage_InventoryTransferScreen,
    EFrontendPage_Message,
    EFrontendPage_PhotoMode,
    EFrontendPage_ReportBase,
    EFrontendPage_PhotoBaseForUpload,
    EFrontendPage_BaseUpload,
    EFrontendPage_BasePartsMenu,
    EFrontendPage_BasePartPalette,
    EFrontendPage_Popup,
    EFrontendPage_Maintenance,
    EFrontendPage_Portal,
    EFrontendPage_PortalRunes,
    EFrontendPage_PortalActivate,
    EFrontendPage_PortalUaDisplay,
    EFrontendPage_Refiner,
    EFrontendPage_SystemHoover,
    EFrontendPage_EggMachine,
    EFrontendPage_VehicleRace,
    EFrontendPage_ManageFleet,
    EFrontendPage_ManageExpeditions,
    EFrontendPage_ExpeditionDebrief,
    EFrontendPage_FrigateDetails,
    EFrontendPage_FrigateCaptain,
    EFrontendPage_ExpeditionDetails,
    EFrontendPage_ExpeditionSelection,
    EFrontendPage_ExpeditionOutfitting,
    EFrontendPage_Customisation,
    EFrontendPage_Teleporter,
    EFrontendPage_Teleporter_Nexus,
    EFrontendPage_ByteBeat,
    EFrontendPage_BaseGridPart,
    EFrontendPage_UnlockItemTree,
    EFrontendPage_CreatureFeeder,
    EFrontendPage_CreatureHarvester,
    EFrontendPage_Multiplayer_MissionList,
    EFrontendPage_Multiplayer_MissionDescription,
    EFrontendPage_CraftingTree,
    EFrontendPage_ByteBeatSwitch,
    EFrontendPage_RadialInteraction,
    EFrontendPage_Pet,
    EFrontendPage_IntermediateInteraction,
    EFrontendPage_ByteBeatLibrary,
    EFrontendPage_SettlementHub,
    EFrontendPage_SettlementJudgement,
    EFrontendPage_RocketLockerInventory,
    EFrontendPage_SquadronRecruitment,
    EFrontendPage_SquadronManagement,
    EFrontendPage_SquadronPilotDetails,
    EFrontendPage_NumPages,
};

enum eShipOperation
{
    EShipOperation_None,
    EShipOperation_Teleport,
    EShipOperation_Full,
};

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