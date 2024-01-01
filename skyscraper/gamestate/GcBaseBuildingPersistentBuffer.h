/**
 * @file GcBaseBuildingPersistentBuffer.h
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

#include <networking/GcNetworkSynchronisedBuffer.h>
#include <toolkit/core/types/TkID.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <toolkit/networking/TkUserIdBase.h>
#include <toolkit/utilities/string/TkString.h>

#include <gamestate/basebuilding/gcpersistentbbobjectdata.meta.h>

SKYSCRAPER_BEGIN

template <typename T>
class PersistentData
{
  public:
    T mData;
    uint16_t miInc;

    virtual ~PersistentData();
    virtual bool IsValid();
};

class cGcBaseBuildingPersistentBuffer : public cGcNetworkSynchronisedBuffer
{
  public:
    class BaseBuildingPersistentData : public PersistentData<cGcPersistentBBObjectData>
    {
        virtual ~BaseBuildingPersistentData() { ; }
    };

    cTkVector<cGcBaseBuildingPersistentBuffer::BaseBuildingPersistentData> maBaseBuildingObjects;
    robin_hood::detail::Table<
        true, 80, uint64_t, std::vector<unsigned short>, robin_hood::hash<uint64_t, void>, std::equal_to<uint64_t>>
        maCurrentPlanetObjects;
    uint64_t muCurrentAddress;
    bool mbDebugPositions;
    cTkUserIdBase<cTkFixedString<64, char>> mNetworkOwnerId;
    unsigned int miBufferIndex;
};

SKYSCRAPER_END