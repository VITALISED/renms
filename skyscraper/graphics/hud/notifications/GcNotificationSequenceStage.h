/**
 * @file GcNotificationSequenceStage.h
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

#include <graphics/2d/GcSlotIcon.h>
#include <graphics/frontend/pages/GcFrontendPageEnum.h>
#include <toolkit/utilities/string/TkString.h>

#include <gamestate/messages/gcstatusmessagemissionmarkup.meta.h>

SKYSCRAPER_BEGIN

enum eMessageCategory
{
    EMessageCategory_Info,
    EMessageCategory_Mission,
    EMessageCategory_Danger,
    EMessageCategory_UrgentInfo,
    EMessageCategory_NumTypes,
};

class cGcNotificationSequence;
class cGcNotificationSequenceGroup;

class cGcNotificationSequenceStage
{
  public:
    cTkFixedString<512, char> mText;
    std::function<bool(cGcNotificationSequenceStage *)> mCallback;
    float mfStartTime;
    float mfStartGameTime;
    float mfVisibleTime;
    cGcSlotIcon mIcon;
    eFrontendPage mePageHint;
    eMessageCategory meCategory;
    TkID<128> mInventoryHint;
    cGcNotificationSequence *mpMission;
    cGcNotificationSequenceGroup *mpGroup;
    const char *mpacDebugName;
    cTkFixedString<1024, char> mDebugLog;
    bool mbDebugSkip;

    virtual ~cGcNotificationSequenceStage();
    virtual void SetText(const char *);
    virtual void GetText(cTkFixedString<512, char> *);
    virtual void GetTitle(cTkFixedString<128, char> *);
    virtual bool OverridesTitle();
    virtual void GetFormattedObjective(cTkFixedString<128, char> *);
    virtual void GetFormattedObjectiveTip(cTkFixedString<1024, char> *);
    virtual bool FormatsObjectiveText();
    virtual void GetTitleForCodeGroup(cTkFixedString<128, char> *);
    virtual void NotifyNewlyVisible();
    virtual bool BlocksTimedScans();
    virtual bool OverridesMissionSurveyText();
    virtual bool BlocksVehicleScans(TkID<256>);
    virtual bool NeedsGPSHint();
    virtual const TkID<256> *GetCurrentScanEventTarget(const TkID<256> *result);
    virtual bool DisableIcon();
    virtual bool DisableTitlePrefix();
    virtual bool OverrideWithDangerColour();
    virtual bool AllowMissionRestart();
    virtual bool BlockPirateMessage();
    virtual bool BlockPulseEncounters();
    virtual bool SuppressMessages();
    virtual TkID<128> *GetBuildMenuHint(TkID<128> *result);
    virtual eMissionMarkup GetStatusMessageMarkup();
    virtual bool AllowAutoEndPinnedMission();
    virtual bool OverridesIcon();
    virtual bool EncouragesFightingSentinels();
    virtual void Activate();
    virtual bool IsWaitingForCompletionMessage();
};

SKYSCRAPER_END