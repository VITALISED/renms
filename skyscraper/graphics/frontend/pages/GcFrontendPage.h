#pragma once

#include <skyscraper.h>

#include <toolkit/graphics/utilities/TkModelResourceRenderer.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <toolkit/utilities/TkStrongType.h>

#include <reality/gcunlockableitemtree.meta.h>
#include <toolkit/utilities/input/actions/gcinputactions.meta.h>

SKYSCRAPER_BEGIN

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