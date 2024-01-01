/**
 * @file GcPlayerFreighterOwnership.h
 * @author VITALISED & Contributors
 * @since 2023-12-09
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

#include <networking/GcNetworkPlayerEventsHandler.h>
#include <networking/messages/GcNetworkFreighterOwnershipSyncMessage.h>
#include <toolkit/networking/TkUserIdBase.h>
#include <toolkit/utilities/containers/TkClassPool.h>

#include <gamestate/gcuniverseaddressdata.meta.h>
#include <reality/gcalienrace.meta.h>
#include <simulation/player/gcscaneffectdata.meta.h>
#include <toolkit/tkmodelresource.meta.h>
#include <utilities/data/gcresourceelement.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerFreighterOwnership : public INetworkPlayerEventsHandler
{
  public:
    enum eMeshRefreshState
    {
        ReadyForRefresh,
        Generating,
    };

    TkHandle mGroupRootNode;
    cTkFixedString<32, char> mCustomFreighterName;
    cTkUserIdBase<cTkFixedString<64, char>> mOwnerId;
    cGcNetworkFreighterOwnershipSyncMessage mFreighterOwnershipSyncMessage;
    cGcUniverseAddressData mFreighterLocation;
    bool mbIsDismissed;
    cTkSeed mFreighterHomeSystemSeed;
    cTkSeed mPlayerFreighterSeed;
    uint64_t mu64UTCTimeOfLastSpawn;
    cGcResourceElement mFreighterResource;
    cGcResourceElement mFreighterNPCResource;
    cTkModelResource mHangarResource;
    cTkSmartResHandle mPlayerFreighterResHandle;
    TkHandle mPlayerFreighterNode;
    /*cGcAISpaceshipComponent*/ uintptr_t *mpPlayerFreighterComponent;
    cTkClassPoolHandle mInvalidAsteroidArea;
    cTkMatrix34 mFreighterMatrix;
    float mfRequestedFreighterSpawnTime;
    eAlienRace meRace;
    cGcScanEffectData mFreighterPreviewScanData;
    cTkColour mFreighterPreviewColour;
    TkHandle mPreviewFreighterNode;
    TkHandle mFalseFreighterNode;
    float mfFreighterPreviewFirstActiveTime;
    float mfFreighterPreviewLastActiveTime;
    bool mbShowFreighterPreview;
    bool mbNextSpawnIsInstant;
    bool mbSpawnFreighterWhenResourceIsLoaded;
    bool mbFreighterIsAbsentDueToWarpingWithPlayersOnBoard;
    bool mbHaveFreighterOwnershipSyncMessage;
    bool mbWantToDestroy;
    bool mbHasTeleporter;
    bool mbIsActiveFreighterInSystem;
    TkID<128> mFreighterEngineEffect;
    cGcNetReplicatedFreighterColourData mReplicatedCustomColours;
    bool mbShouldRefreshMesh;
    cGcPlayerFreighterOwnership::eMeshRefreshState mMeshRefreshState;
};

SKYSCRAPER_END