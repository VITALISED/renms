/**
 * @file GcNotificationSequence.h
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

#include <graphics/hud/notifications/GcNotificationSequenceGroup.h>
#include <graphics/hud/notifications/GcNotificationSequenceStage.h>
#include <graphics/hud/notifications/GcNotifyGenericSection.h>
#include <toolkit/core/types/TkID.h>
#include <toolkit/core/types/TkTypes.h>
#include <toolkit/simulation/TkSeed.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/string/TkString.h>

#include <gamestate/gcplayermissionparticipant.meta.h>
#include <gamestate/gcplayermissionparticipanttype.meta.h>
#include <gamestate/gcplayermissionprogress.meta.h>
#include <simulation/missions/gcgenericmissionsequence.meta.h>
#include <toolkit/tktextureresource.meta.h>

SKYSCRAPER_BEGIN

enum eMultiplayerMissionType
{
    EMultiplayerMissionType_Standard,
    EMultiplayerMissionType_Mystery,
    EMultiplayerMissionType_Quicksilver,
    EMultiplayerMissionType_Weekend,
    EMultiplayerMissionType_NotMultiplayer,
};

class cGcNotificationSequence
{
  public:
    TkID<128> mId;
    cTkVector<cGcNotificationSequenceStage *> mapSequence;
    cTkVector<cGcNotificationSequenceGroup *> mapGroups;
    uint64_t mUserData;
    int miActiveStage;
    int miBeginCheckFrequency;
    cTkVector<TkID<128>> maPendingMessages;
    bool mbNewPendingMessages;
    cTkVector<cGcNotifyGenericSection> maGenericSections;
    cTkFixedString<128, char> mDebugName;
    bool mbPendingActivate;
    cTkSeed mSeed;
    int mSequenceFlags;
    bool mbUsingFallbackScanEvents;

    virtual ~cGcNotificationSequence();
    virtual bool Update();
    virtual bool IsAppropriate();
    virtual void GetMissionDataTitle(cTkFixedString<128, char> *);
    virtual void GetTitle(cTkFixedString<128, char> *);
    virtual void GetSubtitle(cTkFixedString<256, char> *);
    virtual void GetDescription(cTkFixedString<512, char> *);
    virtual const cTkTextureResource *GetMissionIcon();
    virtual const cTkTextureResource *GetMissionIconSelected();
    virtual const cTkTextureResource *GetMissionIconNotSelected();
    virtual bool ShowFutureObjectives();
    virtual bool IsPrimary();
    virtual bool IsLegacy();
    virtual eMissionClass GetClass();
    virtual TkID<128> *UseCommunityMissionForLog(TkID<128> *result);
    virtual bool IsCritical();
    virtual bool BlocksPinning();
    virtual bool IsProcedural();
    virtual bool DataAllowsRenounce();
    virtual void RefreshLogInfo();
    virtual eMessageCategory GetCurrentCategory();
    virtual cTkColour *GetCurrentColour(cTkColour *result);
    virtual const cGcSlotIcon *GetCurrentIcon();
    virtual TkStrongType<int, TkStrongTypeIDs::TkResHandleID> *GetIconAtStage(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> *result, int);
    virtual eFrontendPage GetCurrentFrontendPageHint();
    virtual TkID<128> *GetCurrentInventoryHint(TkID<128> *result);
    virtual void GetCurrentFrontendPageLocID(TkID<256> *);
    virtual TkID<128> *GetCurrentBuildMenuHint(TkID<128> *result);
    virtual bool CheckOptionCondition(const TkID<256> *, cTkFixedString<1024, char> *);
    virtual void WriteItemText(cTkFixedString<512, char> *, bool);
    virtual void Restart();
    virtual void Cancel();
    virtual void DebugNguiMissionInfo();
    virtual bool HasText();
    virtual bool GetText(cTkFixedString<512, char> *);
    virtual eParticipantType GetParticipantTypeFromPointer(cGcPlayerMissionParticipant *);
    virtual cGcPlayerMissionParticipant *GetParticipantPointerFromType(eParticipantType);
    virtual int GetNumberOfParticipants();
    virtual bool HasBeenHandedIn();
    virtual void NGuiRender();
    virtual void Load(const cGcPlayerMissionProgress *, int);
    virtual void Save(cGcPlayerMissionProgress *);
    virtual bool CanBegin();
    virtual bool CanBeRenounced();
    virtual bool IsForcingPageHint();
    virtual bool IsForcingBuildMenuHint();
    virtual bool IsTelemetryUpload();
    virtual eMultiplayerMissionType GetMultiplayerMissionType(const bool);
};

SKYSCRAPER_END