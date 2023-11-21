/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <skyscraper.h>

#include <application/states/GcApplicationState.h>
#include <graphics/ngui/GcNGuiManager.h>
#include <toolkit/utilities/TkStrongType.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <gamestate/gcinventoryelement.meta.h>

SKYSCRAPER_BEGIN

class cGcApplicationDeathState : public cGcApplicationState
{
  public:
    typedef cGcAsyncLoadOps::Operation Phase;

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

    ~cGcApplicationDeathState();
    void Construct();
    void Prepare(cTkFSMState *, const void *);
    void Update(float);
    void Release(cTkFSMState *, const void *);
    void Render(EgRenderParity::List);
};

SKYSCRAPER_END