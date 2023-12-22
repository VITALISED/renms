/**
 * @file GcHUDManager.h
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

#include <gamestate/GcInventoryStore.h>
#include <graphics/hud/GcPhotoManager.h>
#include <graphics/hud/GcPlayerHUD.h>
#include <graphics/hud/GcPlayerNotifications.h>
#include <graphics/hud/GcShipHUD.h>
#include <networking/GcNetworkRpcCall.h>
#include <simulation/player/GcQuickMenu.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>

#include <gamestate/gcwordgroupknowledge.meta.h>
#include <graphics/gchudmanagerdata.meta.h>
#include <graphics/hud/gcscannericons.meta.h>
#include <reality/gcrarity.meta.h>
#include <simulation/missions/sequences/gcmissionsequencedetailmessagepoint.meta.h>
#include <toolkit/animation/tkcurvetype.meta.h>

SKYSCRAPER_BEGIN

enum eHUDStartup
{
    EHUDStartup_WaitingForInit,
    EHUDStartup_Startup,
    EHUDStartup_Booting,
    EHUDStartup_LifeSupport,
    EHUDStartup_Shield,
    EHUDStartup_ShieldEffect,
    EHUDStartup_Scanner,
    EHUDStartup_Jetpack,
    EHUDStartup_Weapon,
    EHUDStartup_Finishing,
    EHUDStartup_DiscoverPlanet,
    EHUDStartup_Done,
    EHUDStartup_Inactive,
    EHUDStartup_NumTypes,
};

struct MissionMessage
{
    cTkFixedString<128, char> msTitle;
    cTkFixedString<256, char> msMessage;
    cTkFixedString<256, char> msSubtitle;
    float mfDisplayTime;
    cTkColour mColour;
    unsigned int mAudioCue;
    class cTkSmartResHandle mIconTexture;
    bool mbActive;
    eFrontendPage meFrontendPageHint;
    int miWikiCategoryIndex;
    int miWikiTopicIndex;
};

struct MissionDetailMessage
{
    enum eRenderState
    {
        ERenderState_SetText,
        ERenderState_WaitAFrame,
        ERenderSTate_FixSizes,
        ERenderSTate_Done,
    };

    TkID<256> msTitle;
    TkID<256> msDescription;
    TkID<256> mImageID;
    unsigned int mAudioEvent;
    TkID<128> mPinnedItemID;
    cTkDynamicArray<cGcMissionSequenceDetailMessagePoint> maPoints;
    MissionDetailMessage::eRenderState meState;
};

class cGcTransition
{
  public:
    float mTValue;
    float mTDelta;
    eCurve mCurveFunction;
    std::function<void(void)> mOnCompletionFn;
    bool mExtraWaitForTextures;
    bool mRunning;
};

struct MessageBase
{
    float mfMessageTime;
    float mfMessageTimeTotal;
    float mfStartTime;
    float mFade;
};

struct OSDMessage : MessageBase
{
    enum ePriority
    {
        EPriority_Low,
        EPriority_High,
        EPriority_StatsMessage,
    };

    enum eTextBoxType
    {
        ETextBoxType_Normal,
        ETextBoxType_Large,
        ETextBoxType_Discovery,
        ETextBoxType_Death,
        ETextBoxType_Stat,
        ETextBoxType_Fancy,
        ETextBoxType_SeasonalMilestone,
        ETextBoxType_SeasonalStage,
        ETextBoxType_NumTypes,
    };

    cTkFixedString<512, char> mTitle;
    cTkFixedString<512, char> mText;
    cTkFixedString<128, char> mFancySubtitle;
    unsigned int mAudioCue;
    cTkModelResourceRenderer *mpThumbnailRenderer;
    cTkSmartResHandle mIconTexture;
    cTkSmartResHandle mStatOrSeasonTexture;
    cGcInventoryElement mItem;
    cGcWordGroupKnowledge mWordGroup;
    bool mbActive;
    OSDMessage::ePriority mePriority;
    bool mbShowInfront;
    OSDMessage::eTextBoxType meTextBoxType;
    cTkColour mBarColour;
    bool mbCenter;
};

struct StatsMessages
{
    cTkVector<OSDMessage> maMessages;
    unsigned int mAudioCue;
    bool mbIsShowing;
    bool mbStatsRequireBars;
};

struct OSDMessageEffect
{
    cGcNGuiLayer *mpLayer;
    float mfStartTime;
};

struct OSDMessageEffectReward : OSDMessageEffect
{
    eRarity meRarity;
    bool mbOverrideColour;
    cTkColour mColour;
};

class cGcHUDManager
{
  public:
    enum eMode
    {
        Game,
        GalaxyMap,
        Death,
    };

    enum TransitionDirection
    {
        In,
        Out,
    };

    struct QueuedMessage
    {
        enum State
        {
            WaitingToRenderThumbnail,
            Rendering,
        };

        cGcHUDManager::QueuedMessage::State mState;
        cTkModelResourceRenderer *mpAssignedModelRenderer;
        cTkSmartResHandle mLiveResHandle;
        cTkFixedString<256, char> mText;
        unsigned int mAudioCue;
        float mTTL;
        float mfMessageTime;
        bool mbShowInfront;
    };

    struct CollectedResource
    {
        cGcInventoryElement mItem;
        cTkFixedString<512, char> mSuffix;
        float mfDisplayTime;
        cTkFixedString<512, char> mResourceName;
        bool mbActive;
        float mfAnimateAmountTotalTime;
        float mfAnimateAmountTime;
        int miStartingValue;
        bool mbDisplayAsPercentage;
        bool mbNewItemAlert;
        bool mbHideNumbers;
        float mfStartTime;
        bool mbDontBlockReinteraction;
        cTkSmartResHandle mIconOverride;
    };

    union {
        struct
        {
            cGcRpcCallBase *PAMU;
            cGcHUDManagerData *mpData;
            cGcScannerIcons *mpScannerIcons;
            TkAudioObject mAudioObject;
            cGcHUDManager::eMode meHUDMode;
            cGcTransition mSolidOverlayTransition;
            cTkColour mSolidOverlayColour;
            cGcHUDManager::TransitionDirection mSolidOverlayTransitionDirection;
            cGcPlayerHUD mPlayerHUD;
            cGcShipHUD mShipHUD;
            cGcPlayerNotifications mPlayerNotifications;
            cGcPhotoManager mPhotoManager;
            cGcQuickMenu mQuickMenu;
            cGcInventoryStore mChargingInventory;
            float mfCinematicTimer;
            float mfCinematicBarsAnimTime;
            cGcNGuiLayer mCinematicBars;
            cGcNGuiLayer mOSDMessageLayer;
            cGcNGuiLayer *mpDiscoveryTitleLayer;
            cTkVector2 mDiscoveryTitleLayerPos;
            cGcNGuiTextSpecial *mpSkipMsgText;
            cGcNGuiLayer *mpSkipMsgBar;
            float mfSkipMsgAlpha;
            float mfSkipMsgHoldT;
            cTkVector<OSDMessage> mOSDMessages;
            cTkVector<cGcHUDManager::QueuedMessage> mOSDMessageThumbnailRenderQueue;
            OSDMessageEffectReward mOSDMessageRewardEffect;
            cGcNGui mEffectLayer;
            cTkVector<cGcHUDManager::CollectedResource> mCollectedResources;
            cTkVector<MissionMessage> mMissionMessages;
            cTkVector<MissionDetailMessage> mMissionDetailMessages;
            StatsMessages mStatsMessages;
        };
        const int kiNumThumbnailRenderers;
    };
    std::array<cTkModelResourceRenderer, 2> mModelResourceRenderers;
    std::array<bool, 2> mModelResourceRendererUsage;
    DiscoveryResolver::DiscoveryInfo mDiscoveryDisplayInfo;
    bool mbIntroPausedToStart;
    bool mbIntroRequestStart;
    eHUDStartup meIntroStage;
    float mfIntroTimer;
    bool mbIntroStageFirstTime;
    cGcMarkerRenderData mIntroButtonData;
    bool mbIntroPlayingHoldAudio;
    int miIntroPauseFrames;
    float mfStatsMessageDelayTimer;
    bool mbSuppressMarkersAfterNextWarp;
    bool mbHasMissionDetailMessagesOnScreen;
    float mfLastDetailMessageTime;
    float mfLastDetailMessageDismissTime;
    bool mbCreatureMessageRequested;
    bool mbForcedAtlasPath;
    cGcHUDScreensPool mHUDScreensPool;
    bool mbHUDScreensPoolCtr;
    bool mbReloadRequest;
    cTkVector</*cGcInteractionComponent*/ uintptr_t *> maInteractionOffScreenRenderers;

    ~cGcHUDManager() {}
};

SKYSCRAPER_END