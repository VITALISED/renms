/**
 * @file GcFrontendPageSettlementJudgement.h
 * @author VITALISED & Contributors
 * @since 2023-12-11
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

#include <simulation/solarsystem/buildings/GcBuilding.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <gamestate/gcsettlementstate.meta.h>
#include <reality/gcsettlementjudgementdata.meta.h>
#include <reality/gcsettlementperkusefuldata.meta.h>

SKYSCRAPER_BEGIN

class cGcFrontendPageSettlementJudgement
{
  public:
    enum eJudgementDecision
    {
        EJudgementDecision_None = -1,
        EJudgementDecision_Left,
        EJudgementDecision_Right,
    };

    struct sJudgementNPCData
    {
        cTkFixedString<127, char> mNPCName;
        cTkAttachmentPtr mSpawnedNPC;
    };

    cGcSettlementState *mpSettlementState;
    cGcSettlementJudgementData *mpJudgementData;
    cGcFrontendPageSettlementJudgement::eJudgementDecision meSelectedDecision;
    bool mbNeedsSetup;
    bool mbPendingCleanUp;
    bool mbWaitForNPCReactions;
    bool mbJudgementDataSet;
    bool mbPlayingHoldAudio;
    cTkSeed mJudgementSeed;
    cTkSeed mSettlementSeed;
    cTkVector<cTkFixedString<128, char>> maResponseLeftRewardStrings;
    cTkVector<cTkFixedString<128, char>> maResponseRightRewardStrings;
    const cGcBuilding *mpOption1Building;
    const cGcBuilding *mpOption2Building;
    cGcSettlementPerkUsefulData mPerkToRemoveLeft;
    cGcSettlementPerkUsefulData mPerkToRemoveRight;
    cGcSettlementPerkUsefulData mPerkToAwardLeft;
    cGcSettlementPerkUsefulData mPerkToAwardRight;
    cTkVector<cGcFrontendPageSettlementJudgement::sJudgementNPCData> maSpawnedNPCData;
};

SKYSCRAPER_END