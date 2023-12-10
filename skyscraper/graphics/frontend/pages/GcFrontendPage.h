/**
 * @file GcFrontendPage.h
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

#include <gamestate/GcInventoryStore.h>
#include <graphics/frontend/components/GcFrontendStatCircle.h>
#include <graphics/frontend/pages/data/GcCharacterCustomisationPageData.h>
#include <graphics/frontend/pages/data/GcCraftingTreePageData.h>
#include <graphics/frontend/pages/data/GcDiscoveryPageData.h>
#include <graphics/frontend/pages/data/GcFleetPageData.h>
#include <graphics/frontend/pages/data/GcJourneyPageData.h>
#include <graphics/frontend/pages/data/GcMissionPageData.h>
#include <graphics/frontend/pages/data/GcSeasonPageData.h>
#include <graphics/frontend/pages/data/GcStoriesPageData.h>
#include <graphics/frontend/pages/data/GcWikiPageData.h>
#include <graphics/frontend/popups/GcFrontendPopup.h>
#include <graphics/ngui/GcFrontendModelRenderer.h>
#include <toolkit/graphics/utilities/TkModelResourceRenderer.h>
#include <toolkit/utilities/containers/TkUnorderedMap.h>

#include <graphics/hud/gcinventoryfilteroptions.meta.h>
#include <graphics/hud/gcinventoryslotactiondata.meta.h>
#include <reality/gccurrency.meta.h>
#include <reality/gctechnologycategory.meta.h>
#include <reality/gcunlockableitemtreegroups.meta.h>
#include <simulation/gcweaponclasses.meta.h>
#include <toolkit/utilities/input/actions/gcinputactions.meta.h>

SKYSCRAPER_BEGIN

enum InventoryChoice
{
    _None = -1,
    Personal,
    Personal_TechOnly,
    Personal_Cargo,
    Weapon,
    Ship,
    Ship_TechOnly,
    Ship_Cargo,
    Freighter,
    Freighter_TechOnly,
    Freighter_Cargo,
    _Vehicle,
    Vehicle_TechOnly,
    Chest1,
    Chest2,
    Chest3,
    Chest4,
    Chest5,
    Chest6,
    Chest7,
    Chest8,
    Chest9,
    Chest10,
    ChestMagic,
    ChestMagic2,
    MaintenanceObject,
    FrontendPage,
    CookingIngredients,
    RocketLocker,
    Num_Choices,
};

struct InventoryData
{
    uint8_t mePlayerInventory[4];
    cTkSmartResHandle mModelResHandle;
    cTkModelRendererData *mpModelRenderData;
    TkID<256> mInventoryName;
};

class InventoryTransferData
{
  public:
    cTkVector<InventoryData> maLeft;
    int miCurrentLeft;
    cTkVector<InventoryData> maRight;
    int miCurrentRight;
};

class cGcInventorySlotAction
{
  public:
    enum Style
    {
        InventoryHint,
        NewSuitPulse,
        NewSuitReveal,
        Repair,
        Charge,
        InstallTech,
        BuildProduct,
        NumStyles,
    };

    uint8_t meInventory[4];
    cGcInventoryIndex mInventoryIndex;
    cGcNGuiLayer *mpSlot;
    bool mbActive;
    bool mbCanAutoScrollToBottom;
    bool mbOffScreen;
    float mfStartTime;
    cGcInventorySlotAction::Style meStyle;
    cGcNGuiLayer mActionSlot;
    cGcInventorySlotActionData *mpActionData;
};

enum FrontendHold
{
    Instant,
    Hold,
    HoldImportant,
    HoldExtremelyImportant,
};

class cGcHoldInteraction
{
  public:
    enum eConfirmState
    {
        EConfirmState_None,
        EConfirmState_Confirming,
        EConfirmState_Confirmed,
    };

    enum eInputAction
    {
        EInputAction_Confirm,
        EInputAction_Transfer,
        EInputAction_Upload,
        EInputAction_DiscoveryUpload,
        EInputAction_Delete,
    };

    enum eButtonHoverState
    {
        EButtonHoverState_None,
        EButtonHoverState_NoneStart,
        EButtonHoverState_Instant,
        EButtonHoverState_InstantStart,
        EButtonHoverState_Long,
        EButtonHoverState_LongStart,
    };

    cGcNGuiLayer *mpConfirm;
    float mfConfirmTime;
    cGcHoldInteraction::eConfirmState meConfirmState;
    int miConfirmByButtonEvent;
    bool mbConfirmActiveThisFrame;
    bool mbNeedsWarning;
    TkAudioObject mAudioObject;
    cGcHoldInteraction::eInputAction meAction;
    bool mbPlayingHoldAudio;
    FrontendHold meButtonHoldType;
    cGcHoldInteraction::eButtonHoverState meButtonHoverState;
    bool mbImportant;

    virtual bool IsActive();
    virtual bool NeedsWarning();
    virtual void EndInteraction();
};

class cGcCountInteraction : public cGcHoldInteraction
{
  public:
    enum eCountState
    {
        ECountState_None,
        ECountState_Counting,
    };

    cGcCountInteraction::eCountState meCountState;
    float mfCountTime;
    bool mbCountedOnce;
    bool mbInstant;
};

class cGcPurchaseableItem
{
  public:
    enum ePurchaseState
    {
        EPurchaseState_None,
        EPurchaseState_Loading,
        EPurchaseState_Purchasable,
        EPurchaseState_Purchased,
        EPurchaseState_Finalise,
        EPurchaseState_ShipReEnter,
        EPurchaseState_Cleanup,
    };

    enum ePurchaseableItem
    {
        EPurchaseableItem_Ship,
        EPurchaseableItem_Weapon,
        EPurchaseableItem_SuitSlot,
        EPurchaseableItem_Freighter,
        EPurchaseableItem_Frigate,
        EPurchaseableItem_ShipSlot,
        EPurchaseableItem_FreighterSlot,
        EPurchaseableItem_WeaponSlot,
        EPurchaseableItem_SquadronPilot,
        EPurchaseableItem_ShipSlotAlien,
    };

    cGcPurchaseableItem::ePurchaseState mePurchaseState;
    cGcPurchaseableItem::ePurchaseableItem mItemType;
    cTkSmartResHandle mItemResource;
    TkHandle mItemNode;
    cTkSeed mSeed;
    bool mbIsFree;
    bool mbIsGift;
    bool mbIsReward;
    int miLevel;
    int miCost;
    eCurrency meCurrency;
    bool mbCompareBeforePurchase;
    bool mbAddAdditionalItem;
    eShipClass meShipClass;
    eWeaponStatClass meWeaponStatClass;
    TkHandle mShipNPCNode;
    cTkSeed mShipNPCSeed;
    bool mbTransferBaseFromPreviousFreighter;
    cTkFixedString<127, char> mItemName;
    bool mbCustomName;
    cTkFixedString<256, char> mDescription;
    cGcInventoryStore mTransferPlayerInventory;
    cGcInventoryStore mTransferCargoInventory;
    cGcInventoryStore mItemInventory;
    cGcInventoryStore mCargoInventory;
    cGcInventoryStore mTechOnlyInventory;
    bool mbMarkInteractionComplete;
    bool mbReinteractOnDecline;
    bool mbHighlightSlot;
    bool mbCleanResource;
    TkID<128> mLinkedEntitlementId;
    TkID<128> mLinkedEntitlementRewardId;
    TkID<128> mLinkedRewardOrSpecialId;
    TkID<128> mCostId;
    cGcProceduralTextureManager::TaskContext *mpTC;
};

struct TradeOptions
{
    bool mbSell;
    bool mbInSpaceStation;
    bool mbInPlayerFreighter;
    bool mbSpecial;
    bool mbNexusTechShop;
    bool mbSeasonRewards;
    bool mbTwitchRewards;
    bool mbPlatformRewards;
    uint8_t meTradeInventory[4];
    eTechnologyCategory meTechnologyCategory;
};

struct ItemPicking
{
    cGcInventoryElement mItem;
    cGcInventoryIndex mIndex;
    uint8_t meInventory[4];
    cGcInventoryStore *mpInventory;
    bool mbDeployMode;
    bool mbMovingTech;
    bool mbPackingTech;
    bool mbCharging;
};

class cGcFrontendPage
{
  public:
    struct ButtonIcon
    {
        TkStrongType<int, TkStrongTypeIDs::cTkNGuiFontHandleID> miPadIcon;
        uint8_t meSize[4];
        eInputAction meBoundAction;
    };

    struct sNewItemPopupData
    {
        cGcInventoryElement mItem;
        bool mbIsNew;
        cTkFixedString<256, char> mDisplayTechItemCustomTitle;
        cTkVector<TkID<128>> maMultiDisplayTechs;
    };

    cGcFrontendPage::ButtonIcon mPadAIcon;
    cGcFrontendPage::ButtonIcon mPadBIcon;
    cGcFrontendPage::ButtonIcon mPadCIcon;
    cGcFrontendPage::ButtonIcon mPadDIcon;
    cGcFrontendPage::ButtonIcon mPadEIcon;
    cGcFrontendPage::ButtonIcon mPadAOffIcon;
    cGcFrontendPage::ButtonIcon mPadCOffIcon;
    cGcFrontendPage::ButtonIcon mDiscoveryUploadIcon;
    cGcFrontendPage::ButtonIcon mByteBeatPrevIcon;
    cGcFrontendPage::ButtonIcon mByteBeatNextIcon;
    cGcFrontendPage::ButtonIcon mPinRecipeIcon;
    TkStrongType<int, TkStrongTypeIDs::cTkNGuiFontHandleID> maiProductCatagories[9];
    TkStrongType<int, TkStrongTypeIDs::cTkNGuiFontHandleID> maiTechCatagories[5][4];
    TkStrongType<int, TkStrongTypeIDs::cTkNGuiFontHandleID> maiTransferCatagories[6];
    TkStrongType<int, TkStrongTypeIDs::cTkNGuiFontHandleID> maiTransferVehicles[7];
    std::array<cTkModelResourceRenderer, 2> maSecondaryModelRenderers;
    int miLastTechCatagory;
    int miLastProductCatagory;
    int miLastTransferCategory;
    cTkVector2 mCursorCenterOffset;
    unsigned int miDisplayUnits;
    unsigned int muDisplaySpecials;
    unsigned int muDisplayNanites;
    eUnlockableItemTree meUnlockableItemTree;
    int miCurrentUnlockableTreeIndex;
    int miCurrentUnlockableTreeStartIndex;
    cGcDiscoveryPageData mDiscoveryPageData;
    cGcWikiPageData mWikiPageData;
    cGcWikiPageData mCataloguePageData;
    cGcStoriesPageData mStoriesPageData;
    cGcMissionPageData mMissionPageData;
    cGcJourneyPageData mJourneyPageData;
    cGcFleetPageData mFleetPageData;
    cGcSeasonPageData mSeasonPageData;
    cGcCharacterCustomisationPageData mCharacterCustomisationPageData;
    cGcCraftingTreePageData mCraftingTreePageData;
    int miSaveSlotCurrentTimestamp;
    int miSaveSlotPreviousTimestamp;
    int miSaveSlotOldestTimestamp;
    unsigned int muAutosaveIndex;
    bool mbTrackSlotChange;
    cTkUnorderedMap<TkID<128>, int, TkIDUnorderedMap::Hash128> mItemAmounts;
    InventoryTransferData mInventoryTransferData;
    eWikiPageType meSelectedWikiPageType;
    eInventoryFilter meSelectedInventoryFilter;
    TkID<128> mInventoryHighlightRequest;
    bool mbPopupHasPriorityForInventoryActions;
    cGcNGuiLayer *mpHoverLayer;
    bool mbHovering;
    cGcNGuiLayer *mpPage;
    cGcNGuiLayer *mpPicking;
    eFrontendPage mePage;
    cGcInventorySlotAction mInventorySlotAction;
    cGcInventoryStore mTemporaryInventoryStore;
    TkID<128> mActiveBuildProduct;
    int miNumProductsToBuild;
    cGcFrontendPopup mHoverPopup;
    cGcFrontendPopup mActionPopup;
    ePopupAction meActionPopupState;
    float mfActionPopupDebounceTime;
    float mfHoverPopupDebounceTime;
    cGcInventoryIndex mActionSlot;
    bool mbActive;
    bool mbActionPopupRendering;
    bool mbDisableHover;
    bool mbInnerContentActive;
    bool mbScrollbarActive;
    bool mbScrollbarActiveLastFrame;
    std::array<int, 28> maiInventoriesWithOffscreenEdits;
    float mfActiveTime;
    float mfActivationTime;
    int miPopupOffset;
    int miHighlightedInteractionOption;
    cGcHoldInteraction mConfirm;
    cGcHoldInteraction mTransfer;
    cGcHoldInteraction mUpload;
    cGcHoldInteraction mDiscoveryUpload;
    cGcHoldInteraction mDelete;
    cGcCountInteraction mCount;
    cGcFrontendStatCircle maStats[8];
    cGcFrontendModelRenderer *mpModelRenderer;
    cTkMatrix34 mInteractionMatrix;
    cGcPurchaseableItem mPurchaseableItem;
    cTkVector<cGcFrontendPage::sNewItemPopupData> maDislayTechPopupData;
    bool mbRemoveItemPopup;
    TradeOptions mTradeOptions;
    ItemPicking mPickedItem;
    long double mf64LastStackSizeChangeTime;
    float mfStackSizeChangeRate;
    bool mbPickingFinishing;
    int miSelectedSubInventoryIndex;
    cGcInventoryIndex mSelectedInventoryItemIndex;
    int miExpandedSubInventoryIndex;
    cTkVector<InventoryChoice> maCachedFreighterInventories;
    cTkAttachmentPtr mpPreviousInteractionAttachment;
    cTkAttachmentPtr mpInteractionAttachment;
    cTkAttachmentPtr mpPendingInteractionAttachment;
    cTkAttachmentPtr mpMaintenanceAttachment;
    cTkAttachmentPtr mpPendingMaintenanceAttachment;
    cTkAttachmentPtr mpPreviousMaintenanceAttachment;
};

SKYSCRAPER_END