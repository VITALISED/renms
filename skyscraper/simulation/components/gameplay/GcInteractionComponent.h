#pragma once

#include <skyscraper.h>

#include <audio/GcByteBeat.h>
#include <gamestate/GcMsgBeaconManager.h>
#include <graphics/frontend/pages/GcFrontendPage.h>
#include <simulation/components/gameplay/interaction/GcInteraction.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <toolkit/utilities/containers/TkUnorderedMap.h>
#include <utilities/animation/GcSimpleAnimationQueue.h>

#include <reality/gcalienpuzzletable.meta.h>
#include <simulation/components/gameplay/gcinteractioncomponentdata.meta.h>

SKYSCRAPER_BEGIN

enum eInteractionUpdateRequest
{
    EUpdateRequest_None,
    EUpdateRequest_SummonShip,
};

enum eInteractionEvent
{
    EInteractionEvent_None,
    EInteractionEvent_StartSequence,
    EInteractionEvent_FinishSequence,
    EInteractionEvent_DoOptionSequence,
    EInteractionEvent_DoRewardSequence,
    EInteractionEvent_DoOption,
    EInteractionEvent_DoOptionNoSave,
    EInteractionEvent_DoMarkComplete,
    EInteractionEvent_GiveReward,
    EInteractionEvent_HandInMission,
    EInteractionEvent_RenounceMission,
    EInteractionEvent_DialogDone,
    EInteractionEvent_DescriptionDone,
    EInteractionEvent_InteractionEnded,
    EInteractionEvent_InteractionDismissed,
    EInteractionEvent_IdleMood,
    EInteractionEvent_SetProp,
    EInteractionEvent_ClaimPlayerBase,
    EInteractionEvent_UploadBase,
    EInteractionEvent_ReportBase,
    EInteractionEvent_DeleteBase,
    EInteractionEvent_MoveLegacyBaseHere,
    EInteractionEvent_ConvertNPCBaseToPlayerBase,
    EInteractionEvent_ClaimSettlement,
    EInteractionEvent_Upload_Message_Beacon,
    EInteractionEvent_Report_Content,
    EInteractionEvent_Block_User,
    EInteractionEvent_ShowUI,
    EInteractionEvent_HideUI,
    EInteractionEvent_CameraOn,
    EInteractionEvent_CameraOff,
    EInteractionEvent_AnimateIn,
    EInteractionEvent_AnimateOut,
    EInteractionEvent_LookAtOn,
    EInteractionEvent_LookAtOff,
    EInteractionEvent_Regenerate_Name,
    EInteractionEvent_Regenerate_Description,
    EInteractionEvent_FE_Title_On,
    EInteractionEvent_FE_Title_Off,
    EInteractionEvent_FE_Dialog_On,
    EInteractionEvent_FE_Start_Talking,
    EInteractionEvent_FE_Dialog_Typeout_Finished,
    EInteractionEvent_FE_Dialog_Off,
    EInteractionEvent_FE_Text_On,
    EInteractionEvent_FE_Text_Off,
    EInteractionEvent_FE_Text_Frame_On,
    EInteractionEvent_FE_Text_Frame_Off,
    EInteractionEvent_FE_Options_On,
    EInteractionEvent_FE_Not_Selected_Options_Off,
    EInteractionEvent_FE_Options_Off,
    EInteractionEvent_FE_Response_On,
    EInteractionEvent_FE_Response_Off,
    EInteractionEvent_FE_TextEntry_On,
    EInteractionEvent_FE_TextEntry_Off,
};

class cGcInteractionComponent : public cTkComponent
{
    cGcInteractionComponentData *mpData;
    cGcInteraction *mpInteraction;
    unsigned __int64 mUA;
    cTkSeed mSeed;
    cTkSeed mShipSeed;
    cTkSeed mMissionSeed;
    TkAudioObject mAudioObject;
    cGcSimpleAnimationQueue mAnimQueue;
    eInteractionUpdateRequest meUpdateRequest;
    cTkVector<eInteractionEvent> maInteractionEvents;
    const cGcAlienPuzzleEntry *mpCachedPuzzle;
    cTkFixedString<127, char> mName;
    cTkFixedString<127, char> mNameCached;
    cTkFixedString<127, char> mNameLoc;
    cTkFixedString<127, char> mNameLocCached;
    cTkFixedString<127, char> mItemName;
    cTkFixedString<127, char> mItemNameLoc;
    cTkFixedString<128, char> mDescription;
    cTkFixedString<128, char> mBaseName;
    cTkFixedString<128, char> mBaseDescription;
    std::shared_ptr<cGcMsgBeacon> mMessageBeacon;
    cGcByteBeat *mpByteBeat;
    cTkFixedString<64, char> mKeyboardTitle;
    bool mbPlayerOwned;
    std::array<cTkFixedString<1024, char>, 3> maCustomFreighterLogText;
    TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mInteractionIcon;
    cGcNetworkConstants::OnlinePlatformType mePlatformIcon;
    cTkSmartResHandle mModelRes;
    cGcPurchaseableItem mPurchaseableItem;
    cGcPurchaseableItem mPurchaseableItemAlt;
    bool mbShipIsPlayerShip;
    cTkTimerTemplate<0> mAttractTimer;
    bool mbAttractStarted;
    bool mbCanAttract;
    float mfParallaxOffsetX;
    float mfParallaxOffsetY;
    TkID<128> mIdleAnim;
    TkID<128> mGreetAnim;
    TkID<128> mHappyAnim;
    TkID<128> mAngryAnim;
    TkID<128> mNeutralAnim;
    eInteractionType meSecondaryInteractionType;
    ActivationCost mActivationCost;
    bool mbIsPlayingEffectAudio;
    bool mbCanTradeWithShipInventory;
    int miCurrentModelRenderDataIndex;
    int miNextModelRenderDataIndex;
    float mfModelRenderDataBlendTime;
    float mfModelRenderDataBlendTimer;
    TkID<256> mForcedInteractionID;
    TkID<256> mForcedChainedInteractionID;
    TkID<128> mPuzzleOverrideChainControllingMission;
    TkID<256> mPuzzleMissionChainInteractionID;
    cTkVector3 mCentreOffset;
    TkHandle mModelNode;
    const cTkDynamicArray<cGcAlienPuzzleMissionOverride> *mpPuzzleMissionOverrideTable;
    cGcBuilding *mpBuilding;
    eInteractionType meInteractionTypeOverride;
    eFrontendPage meOverridePage;
    cTkVector<cGcAlienPuzzleOption> maAdditionalOptions;
    TkHandle mEffectNode;
    cTkUnorderedMap<TkID<128>, int, TkIDUnorderedMap::Hash128> mAmountSubstanceBought;
    cTkUnorderedMap<TkID<128>, int, TkIDUnorderedMap::Hash128> mAmountProductBought;
    cTkUnorderedMap<TkID<128>, int, TkIDUnorderedMap::Hash128> mAmountTechnologyBought;
    cGcNPCComponent *mpNPCComponent;
    cTkAnimationComponent *mpAnimationComponent;
    TkHandle mSecondaryModelNode;
    TkHandle mInteractLocator;
    TkHandle mInteractOriginLocator;
    TkHandle mInteractInWorld;
    TkHandle mOverrideInWorld;
    cGcInteractionInterface mUIInterface;
    bool mbUsingSecondaryInteraction;
    bool mbIsBeingInteractedWith;
    bool mbIsWaitingForInteracteeReady;
    bool mbInteractionComplete;
    bool mbInteractionSuccess;
    bool mbInteractionAborted;
    bool mbIsOnSpaceStation;
    float mfInteractionStartTime;
    cGcAlienPuzzleEntry mRewardPuzzleEntry;
    bool mbRewardOverrideSet;
    bool mbQueuedReinteraction;
    bool mbSkipDialogEvents;
    bool mbInteractionForcedLocked;
    TkID<256> mQueuedPurchaseSuccessInteraction;
    TkID<256> mQueuedPurchaseDeclineInteraction;
    bool mbMessageInteractionChecked;
    bool mbMessageInteractionAllowed;
    const float kfPersInteractionPlanetLength;
    cTkVector3 mPersInteractionPosition;
    sComponentBaseObjectHandle mBaseObjectHandle;
    cGcVehicleCheckpointComponent *mpStartCheckpoint;
    cGcPortalComponent *mpPortalComponent;
    cTkUserIdBase<cTkFixedString<64, char>> mNetworkPlayerId;
    bool mbForceFixed;
    bool mbAllowInterpFromLastInteraction;
    cTkFixedString<64, char> mFocusJoint;
    cTkFixedString<64, char> mNextFocusJoint;
    float mfCameraRotationOffset;
    float mfCameraPitchOffset;
    bool mbCanInteract;
    bool mbClaimBaseModelActivation;
    bool mbHasVisited;
    bool mbAllowedToUseInteractionClass;
    eTechnologyCategory meTechShopTechCategoryOverride;
    TkID<128> mAcceptedFoodProductID;
    float mfAcceptedFoodProductValue;
    bool mbUseFirstFreighter;
    eMood meCachedMood;
    unsigned __int64 muNPCThoughtsLastActivatedUTC;
    bool mbNPCThoughtsActive;
    bool mbHasForcedInteractionPosition;
    cTkVector3 mvForcedInteractionPosition;
    std::vector<cGcInteractionComponent::NPCTrigger, TkSTLAllocatorShim<cGcInteractionComponent::NPCTrigger, 4, -1>>
        maeNPCTriggers;
};

SKYSCRAPER_END