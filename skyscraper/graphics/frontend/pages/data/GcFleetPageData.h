/**
 * @file GcFleetPageData.h
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

#include <gamestate/GcFleetExpedition.h>
#include <gamestate/GcFleetFrigate.h>
#include <graphics/frontend/pages/GcFrontendPageEnum.h>
#include <graphics/hud/elements/GcHUDMarker.h>

SKYSCRAPER_BEGIN

enum eFleetPageMode
{
    EFleetPageMode_Default,
    EFleetPageMode_SelectFrigateForExpedition,
};

enum eDebriefLogEntryStage
{
    EDebriefLogEntryStage_ShowingTitle,
    EDebriefLogEntryStage_ShowingDescription,
    EDebriefLogEntryStage_ShowingReward,
    EDebriefLogEntryStage_Complete,
};

class cGcFleetPageData
{
  public:
    cGcMarkerRenderData mBeginDial;
    cGcFleetExpedition *mpSelectedExpedition;
    cGcFleetFrigate *mpSelectedFrigate;
    int miCurrentFleetPage;
    int miCurrentExpeditionPage;
    int miCurrentExpeditionDetailsPage;
    int miSelectedPowerupIndex;
    eFleetPageMode mePageMode;
    float mfLeaveScreenTimer;
    float mfFeedFrigateStartTime;
    float mfDebriefLetterTimer;
    int miDebriefLogEntryLettersAddedLastFrame;
    int miDebriefLogEntryLettersShown;
    int miDebriefLogEntriesShown;
    eDebriefLogEntryStage meDebriefLogEntryStage;
    bool mbAddedCRDelay;
    bool mbShownDebrief;
    bool mbExpeditionHasBeenChosen;
    cTkVector3 mFocusFrigatePosition;
    cTkVector3 maFocusFrigateTraitPositions[5];
    cGcFleetFrigate mFrigateBeingPurchased;
    const cGcFleetFrigate *mpHighlightedFrigate;
    const cGcFleetFrigate *mpNewHighlightedFrigate;
    const cGcFleetExpedition *mpHighlightedExpedition;
    const cGcFleetExpedition *mpNewHighlightedExpedition;
    eFrontendPage meReturnPage;
    TkHandle mFocusNode;
    TkHandle mNewFocusNode;
    eExpeditionCategory meFrigateListPrimaryCategory;
    bool mbSortFrigateListRequested;
    bool mbPlayingDebriefAudio;
};

SKYSCRAPER_END