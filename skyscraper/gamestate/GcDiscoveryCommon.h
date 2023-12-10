/**
 * @file GcDiscoveryCommon.h
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

#include <atlas/broker/GcAtlasBroker.h>
#include <toolkit/system/memory/pools/TkMemoryPool.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <reality/gcdiscoverytype.meta.h>

SKYSCRAPER_BEGIN

class cGcDiscoveryPayload : AutoPooled<19>
{
  public:
    unsigned int kuSignificantElements;
    std::array<uint64_t, 5> mau64Storage;
    unsigned int muNumElements;
};

class cGcDiscoveryData : AutoPooled<19>
{
  public:
    uint64_t mUniverseAddress;
    cGcDiscoveryPayload mu64Payload;
    eDiscoveryType meType;
};

template <int Amount>
class cGcDiscoveryDataRing
{
    std::array<cGcDiscoveryData, Amount> mDataBuffer;
    std::array<uint64_t, Amount> mHashBuffer;
    unsigned int muWriteIndex;
    unsigned int muValidItems;
};

struct DefaultDiscoveryDataHashing
{};

class cGcDiscoveryMetadata : AutoPooled<19>
{
  public:
    cTkFixedString<127, char> mCustomName;
    bool mbHasCustomName;
};

class cGcDiscoveryRecord : AutoPooled<19>
{
  public:
    cGcDiscoveryData mData;
    cGcDiscoveryOwner mOwnership;
    cGcDiscoveryMetadata mMetadata;
    cTkFixedString<64, char> mRID;
    cTkFixedString<3, char> mPTK;
    uint8_t mFlags;
};

template <typename Hash, int MemPoolIdx>
class cGcDiscoveryStoreImpl : AutoPooled<19>
{
  public:
    struct ConstIterator
    {
        // std::const_iterator<std::_Vector_val<std::_Simple_types<robin_hood::detail::Table<
        //     1, 80, unsigned __int64, cGcDiscoveryRecord *, robin_hood::hash<unsigned __int64, void>,
        //     std::equal_to<unsigned __int64>, 19> *>>>
        //     mArrayIterator;
        // std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<robin_hood::detail::Table<
        //     1, 80, unsigned __int64, cGcDiscoveryRecord *, robin_hood::hash<unsigned __int64, void>,
        //     std::equal_to<unsigned __int64>, 19> *>>>
        //     mArrayIteratorEnd;
        // robin_hood::detail::Table<
        //     1, 80, unsigned __int64, cGcDiscoveryRecord *, robin_hood::hash<unsigned __int64, void>,
        //     std::equal_to<unsigned __int64>, 19>::Iter<1>
        //     mMapIter;

        cTkVector<robin_hood::detail::Table<
            true, 80, uint64_t, cGcDiscoveryRecord *, robin_hood::hash<uint64_t, void>,
            std::equal_to<uint64_t>>>::const_iterator mArrayIterator;

        cTkVector<robin_hood::detail::Table<
            true, 80, uint64_t, cGcDiscoveryRecord *, robin_hood::hash<uint64_t, void>,
            std::equal_to<uint64_t>>>::const_reverse_iterator mArrayIteratorEnd;

        robin_hood::detail::Table<
            true, 80, uint64_t, cGcDiscoveryRecord *, robin_hood::hash<uint64_t, void>, std::equal_to<uint64_t>>
            mMapIter;

        uint64_t mu64InitChangeID;
        bool lbMapIterValid;
    };

    cTkVector<robin_hood::detail::Table<
        true, 80, uint64_t, cGcDiscoveryRecord *, robin_hood::hash<uint64_t, void>, std::equal_to<uint64_t>> *>
        mDiscoveryMapArray;
    uint64_t muDefaultReservationOfInitialMap;
    uint64_t mu64ChangeID;
};

class cGcManagedDiscovery : AutoPooled<19>
{
  public:
    struct SubmitState
    {
        enum Enum
        {
            Waiting,
            InQueue,
            InProgress,
            Success,
            Failure,
            __EnumTerminator,
            Unspecified,
        };
    };
    cGcDiscoveryRecord *mpRecord;
    cGcManagedDiscovery::SubmitState::Enum meSubmitState;
    AtlasRequestResult meLastFailureResult;
    int mTimestampAtRecord;
    int mTimestampAtUpload;
};

class cGcDiscoveryExport : AutoPooled<19>
{
  public:
    struct Planet
    {
        const cGcDiscoveryRecord *mpData;
        uint64_t mu64UA;
        int miSortTimestamp;
        cTkVector<cGcDiscoveryRecord const *> mDiscoveries;
    };

    struct SolarSystem
    {
        const cGcDiscoveryRecord *mpData;
        uint64_t mu64UA;
        int miSortTimestamp;
        cTkVector<cGcDiscoveryExport::Planet> mPlanets;
    };
    cTkVector<cGcDiscoveryExport::SolarSystem> mSolarSystems;
};

SKYSCRAPER_END