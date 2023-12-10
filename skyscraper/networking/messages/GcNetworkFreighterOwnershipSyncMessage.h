/**
 * @file GcNetworkFreighterOwnershipSyncMessage.h
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

#include <networking/messages/GcNetworkMessage.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <utilities/data/gcresourceelement.meta.h>

SKYSCRAPER_BEGIN

class cGcNetReplicatedFreighterColourData
{
  public:
    int maaiColours[2][3];
};

class cGcNetworkFreighterOwnershipSyncMessage : public cGcNetworkMessage
{
  public:
    cTkMatrix34 mRequestedFreighterMatrix;
    cTkFixedString<32, char> macCustomFreighterName;
    cGcResourceElement mFreighterResource;
    cGcResourceElement mFreighterNPCResource;
    cTkSeed mFreighterHomeSystemSeed;
    cTkSeed mFleetSeed;
    uint64_t mFreighterPackedUA;
    uint64_t mu64UTCTimeOfLastSpawn;
    TkID<128> mEngineEffect;
    cGcNetReplicatedFreighterColourData mCustomColourOptions;
    cTkVector<uint64_t> mau64ExpeditionSeedsSelectedToday;
    uint64_t mu64LastKnownDay;
    bool mbWarpingWithPlayerAboard;
    bool mbIsDismissed;
};

SKYSCRAPER_END