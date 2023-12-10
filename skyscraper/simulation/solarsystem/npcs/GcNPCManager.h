/**
 * @file GcNPCManager.h
 * @author VITALISED & Contributors
 * @since 2023-12-07
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

#include <networking/GcNetworkRpcCall.h>
#include <resources/GcResourceManager.h>
#include <toolkit/resources/TkResource.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/random/TkPersonalRNG.h>

#include <gamestate/gccustomisationpresets.meta.h>
#include <reality/gcalienrace.meta.h>
#include <simulation/npcs/gcnpcanimationsdata.meta.h>
#include <simulation/npcs/gcnpccolourtable.meta.h>
#include <simulation/npcs/gcnpcinteractionsdatatable.meta.h>
#include <simulation/npcs/gcnpcproptable.meta.h>
#include <simulation/npcs/gcnpcreactiondata.meta.h>
#include <simulation/npcs/gcnpcspawntable.meta.h>
#include <simulation/npcs/gcnpcwordreactiontable.meta.h>

SKYSCRAPER_BEGIN

class cGcNPCAnimationManager
{
  public:
    cGcNPCAnimationsData *mpNPCAnimationsData;
    cGcNPCReactionData *mpNPCReactionData;
    cTkPersonalRNG mRNG;
};

class cGcNPCManager
{
  public:
    struct ManagedNPCResource
    {
        cTkSmartResHandle mResHandle;
        eAlienRace meRace;
        TkID<128> mName;
        cGcResourceCustomisation mCustomisation;
        bool mbHasCustomisation;
    };

    cGcRpcCallBase *NPIT;
    cGcRpcCallBase *NPRI;
    cTkVector<cGcNPCManager::ManagedNPCResource> maNPCResources;
    std::array<cTkSmartResHandle, 5> maHabitationNPCs;
    cTkSmartResHandle mFreighterNPCResource[4];
    cGcCustomisationPresets *mpNPCPresetCustomisations;
    cGcNPCSpawnTable *mpNPCSpawnTable;
    cGcNPCColourTable *mpNPCColourTable;
    cGcNPCPropTable *mpNPCPropTable;
    cGcNPCWordReactionTable *mpNPCWordReactions;
    cGcNPCWordReactionTable *mpTerminalWordReactions;
    cGcNPCInteractionsDataTable *mpNPCInteractionsTable;
    cGcNPCAnimationManager mNPCAnimationManager;
    cTkSmartResHandle mNPCChairResources[2];
    cTkSmartResHandle mNPCPropResources[13];
};

SKYSCRAPER_END