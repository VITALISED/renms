/**
 * @file GcPlayerNotifications.h
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

#include <graphics/hud/notifications/GcNotificationScheduler.h>
#include <graphics/hud/notifications/GcNotificationSequence.h>
#include <graphics/ngui/GcNGuiLayer.h>
#include <networking/GcNetworkRpcCall.h>

#include <simulation/missions/gcmissiontable.meta.h>

SKYSCRAPER_BEGIN

class cGcNotificationSequenceEditor
{
  public:
    cGcMissionTable *mpMissionTable;
    cTkVector<cGcGenericMissionSequence *> maMissions;
};

class cGcPlayerNotifications
{
  public:
    class cGcMissionRequest
    {
        std::pair<TkID<128>, cTkSeed> mMission;
        bool mbSetAsCurrent;
        bool mbMultiplayer;
    };

    struct SimpleMessage
    {
        cTkFixedString<128, char> msTitle;
        cTkFixedString<512, char> msMessage;
        cTkColour mColour;
        unsigned int miAudioID;
        bool mbShown;
        eFrontendPage mePageHint;
        cGcSlotIcon mIcon;
        bool mbShowIconBackground;
        bool mbShowIconGlow;
    };

    struct TimedMessage : SimpleMessage
    {
        float mfDisplayTime;
        float mfWaitBeforeDisplayTime;
    };

    struct ConstantMessage : SimpleMessage
    {
        bool mbOn;
        bool mbFresh;
        bool mbCritical;
        float mfVisibleTime;
        float mfTimeTracker;
        eMessageCategory meCategory;
    };

    cGcNGuiLayer mPlayerNotificationLayer;
    cGcNGuiLayer *mpHUDIndicatorLayer;
    cTkVector<cGcPlayerNotifications::cGcMissionRequest> maRequestedMissions;
    cTkVector<cGcPlayerNotifications::cGcMissionRequest> maRestartRequestedMissions;
    cTkVector<std::pair<TkID<128>, cTkSeed>> maRequestedMissionsToComplete;
    cTkVector<std::pair<TkID<128>, cTkSeed>> maCompletedProcMissions;
    cTkVector<cGcNotificationSequence *> maSequences;
    std::pair<TkID<128>, cTkSeed> mPreviousSequence;
    int miSequenceIndex;
    int miHighPrioritySequenceCounter;
    const cGcNotificationSequence *mpLastActiveSequence;
    cTkVector<cGcNotificationSequence *> maDeletedPinnedMissions;
    cTkVector<cGcPlayerNotifications::TimedMessage> mTimedMessages;
    cTkVector<cGcPlayerNotifications::ConstantMessage> maConstantMessages;
    int miCurrentConstantMessageIndex;
    float mfConstantMessageCycleTimer;
    bool mbConstantMessageChanged;
    bool mbNeedsGPSText;
    std::array<float, 6> mafPreviousHazardLevels;
    std::array<float, 6> mafHazardWarningTimer;
    std::array<bool, 6> mabHazardActive;
    TkID<128> mPinnedRecipe;
    TkID<128> mPinnedJourneyMilestone;
    float mfPreviousPersonalShield;
    float mfPreviousShipShield;
    int miPreviousHealth;
    float mfPreviousEnergy;
    float mfPreviousFuel;
    float mfLastHitTime;
    float mfLowEnergyTime;
    float mfExtremePlanetTimer;
    float mfMissionDisplayTimer;
    bool mbMissionDisplayPause;
    int miMissionDisplayIndex;
    float mfJumpTimer;
    float mfThrustTimer;
    float mfJetpackHintTimer;
    float mfLastBoostTime;
    float mfLastJumpTime;
    bool mbBoosted;
    bool mbJumped;
    float mfLastHazardMessageTime;
    float mfTechHintTimer;
    float mfTechHintLastTime;
    TkID<128> mActiveTechHint;
    bool mbRequestedNotify;
    float mfRequestedNotifyTimer;
    float mfRequestedNotifyTime;
    float mfRequestedNotifyDelay;
    eFrontendPage meRequestedNotifyPageHint;
    cGcSlotIcon mRequestedSlotIcon;
    TkID<128> mNextMissionHint;
    eFrontendPage mePageHint;
    TkID<256> mPageLocID;
    TkID<128> mInventoryHint;
    uint8_t mInventoryHintChoice[4];
    cGcSlotIcon mUpperMessageIcon;
    cTkVector2 mSmallIconStartPos;
    cTkVector2 mIconStartPos;
    int miFreighterTutorialStage;
    const cGcPlayerNotifications::SimpleMessage *mpCurrentLowerMessage;
    cGcPlayerNotifications::SimpleMessage mRenderLowerMessage;
    bool mbRenderLowerMessageFresh;
    cGcNotificationSequenceEditor mNotificationSequenceEditor;
    cGcNotificationScheduler mNotificationScheduler;
    bool mbCanShowLowerMessages;
    float mfCabShowLowerMessagesTimer;
    cTkVector<std::pair<TkID<128>, cTkSeed>> maMissionsToClear;
    cTkVector<cGcNotificationSequence *> maRenouncedMissions;
    cTkVector<cGcNotificationSequence *> mapMissionsToRefreshLogInfo;
    std::pair<TkID<128>, cTkSeed> mDebugReloadMission;
    bool mbWeeklyAbandonedFreighterDone;
    int miDailyAbandonedFreighterCount;
    cGcRpcCallBase *SMIS;
    cGcRpcCallBase *RMMM;
    cGcRpcCallBase *RMMS;
};

SKYSCRAPER_END