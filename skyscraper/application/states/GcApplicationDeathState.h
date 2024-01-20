/**
 * @file GcApplicationDeathState.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
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

#include <application/states/GcApplicationState.h>
#include <graphics/ngui/GcNGuiManager.h>
#include <toolkit/core/types/TkTypes.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <gamestate/gcinventoryelement.meta.h>

SKYSCRAPER_BEGIN

class cGcApplicationDeathState : public cGcApplicationState
{
  public:
    virtual ~cGcApplicationDeathState() final;
    virtual void Construct() final;
    virtual void Prepare(cTkFSMState *, const void *) final;
    virtual void Update(float) final;
    virtual void Release(cTkFSMState *, const void *) final;
    virtual void Render(EgRenderParity::List) final;

    void RestoreRenderPipeline();

    enum Phase
    {
        Death,
        WaitForQuote,
        Pause,
        Resurrection,
        Spawn,
        DrainTasks,
        RegenAroundSpawn,
        QuoteFade,
        ResetBitsBeforeStateChange,
        ReturnToModeSelectUI,
        ReturnToGame,
        ResetSeasonSaveData,
        WaitForSave,
    };

    TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mPipelineResource;
    cTkVector<bool> maPreviousPipelineStageState;
    cTkFixedString<512, char> mDeathQuote;
    cTkFixedString<512, char> mDeathAuthor;
    int miDeathQuoteIndex;
    cTkVector3 mDeathPosition;
    cTkVector<cGcInventoryElement> mTrashedItems;
    cGcNGui mGUI;
    float mfQuoteAlpha;
    cGcApplicationDeathState::Phase mePhase;
    float mfTimeDeadTotal;
    float mfTimeToSpendDead;
    float mfTimeToWaitForQuote;
    float mfTimeToSpendGeneratingSpawnLocation;
    float mfRegenDistractionAlpha;
    bool mbDeleteManualSave;
    bool mbPlayerWasInShipWhenKilled;
    bool mbPlayerWasInVehicleWhenKilled;
    bool mbPlayerWasInsidePlanetRangeWhenKilled;
    bool mbPlayerWasLandedWhenKilled;
    bool mbPlayerCrashingOnPlanetFromShip;
    bool mbPlayerWasInAbandonedFreighter;
    bool mbFirstUpdate;
};

SKYSCRAPER_END