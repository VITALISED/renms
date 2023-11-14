#pragma once

#include <skyscraper.h>

#include <gamestate/GcInventoryStore.h>
#include <graphics/2d/GcProceduralTexture.h>
#include <graphics/frontend/pages/data/GcDiscoveryPageData.h>
#include <graphics/frontend/pages/data/GcJourneyPageData.h>
#include <graphics/frontend/pages/data/GcMissionPageData.h>
#include <graphics/frontend/pages/data/GcStoriesPageData.h>
#include <graphics/frontend/pages/data/GcWikiPageData.h>
#include <toolkit/graphics/utilities/TkModelResourceRenderer.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <toolkit/utilities/TkStrongType.h>

#include <reality/gccurrency.meta.h>
#include <reality/gcunlockableitemtree.meta.h>
#include <simulation/gcweaponclasses.meta.h>
#include <toolkit/utilities/input/actions/gcinputactions.meta.h>

SKYSCRAPER_BEGIN

class cGcPurchaseableItem
{
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

class cGcFrontendPage
{
    struct ButtonIcon
    {
        enum Size
        {
            Normal,
            Wide,
            VR,
        };

        TkStrongType<int, TkStrongTypeIDs::cTkNGuiFontHandleID> miPadIcon;
        cGcFrontendPage::ButtonIcon::Size meSize;
        eInputAction meBoundAction;
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
    std::unordered_map<
        TkID<128>, int, TkIDUnorderedMap::Hash128, std::equal_to<TkID<128>>,
        TkSTLAllocatorShim<std::pair<TkID<128> const, int>, 8, -1>>
        mItemAmounts;
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
    __declspec(align(8)) cGcFrontendPopup mHoverPopup;
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
    std::vector<cGcFrontendPage::sNewItemPopupData, TkSTLAllocatorShim<cGcFrontendPage::sNewItemPopupData, 8, -1>>
        maDislayTechPopupData;
    bool mbRemoveItemPopup;
    TradeOptions mTradeOptions;
    ItemPicking mPickedItem;
    long double mf64LastStackSizeChangeTime;
    float mfStackSizeChangeRate;
    bool mbPickingFinishing;
    int miSelectedSubInventoryIndex;
    cGcInventoryIndex mSelectedInventoryItemIndex;
    int miExpandedSubInventoryIndex;
    std::vector<enum InventoryChoice, TkSTLAllocatorShim<enum InventoryChoice, 4, -1>> maCachedFreighterInventories;
    cTkAttachmentPtr mpPreviousInteractionAttachment;
    cTkAttachmentPtr mpInteractionAttachment;
    cTkAttachmentPtr mpPendingInteractionAttachment;
    cTkAttachmentPtr mpMaintenanceAttachment;
    cTkAttachmentPtr mpPendingMaintenanceAttachment;
    cTkAttachmentPtr mpPreviousMaintenanceAttachment;
};

SKYSCRAPER_END