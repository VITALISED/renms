/**
 * @file GcDiscoverySearch.h
 * @author VITALISED & Contributors
 * @since 2023-12-06
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

#include <toolkit/core/types/TkID.h>
#include <toolkit/graphics/utilities/TkModelResourceRenderer.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/string/TkString.h>

#include <reality/gcdiscoveryowner.meta.h>
#include <reality/gcdiscoverytype.meta.h>

SKYSCRAPER_BEGIN

namespace GcDiscoverySearchConstraints
{

class ConstraintBase : AutoPooled<19>
{
  public:
    virtual ~ConstraintBase();
    virtual bool Accept(const cGcDiscoveryRecord *);
};

} // namespace GcDiscoverySearchConstraints

namespace DiscoveryResolver
{

struct NameAndOwnerResult
{
    enum NameResultDetail
    {
        Undiscovered_UsingGeneratedName,
        Discovered_UsingGeneratedName_NoCustomName,
        Discovered_Remote_UsingGeneratedName_UGCIsLockedDown,
        Discovered_Remote_UsingGeneratedName_CustomNameFailedProfanityFilter,
        Discovered_Remote_UsingGeneratedName_DiscoveryHiddenOrBlocked,
        Discovered_UsingCustomName,
        Invalid,
    };

    DiscoveryResolver::NameAndOwnerResult::NameResultDetail meNameResultDetail;
    cTkFixedString<127, char> mDisplayName;
    cTkFixedString<127, char> mLocalisedDisplayName;
    uint8_t meOwnershipResult[4];
    cGcDiscoveryOwner mOwnership;
    bool mbOwnedByCurrentPlayer;
};

struct DiscoveryInfo
{
    struct DiscoveryInfoValue
    {
        TkID<256> mTitle;
        cTkFixedString<128, char> msValue;
        bool mbHighlight;
    };

    cTkFixedString<128, char> msTitle;
    DiscoveryResolver::NameAndOwnerResult mNameAndOwner;
    cTkVector<DiscoveryResolver::DiscoveryInfo::DiscoveryInfoValue> mValues;
    eDiscoveryType meDiscoveryType;
    int miWorth;
    cTkModelResourceRenderer *mpThumbnail;
    float mfDisplayTime;
    float mfDisplayTimer;
    float mfAnimateInTime;
    bool mbNewDiscovery;
    bool mbWeird;
};

} // namespace DiscoveryResolver

class cGcDiscoverySearch : AutoPooled<19>
{
  public:
    enum SortMode
    {
        Unsorted,
        TimestampOldestFirst,
        TimestampNewestFirst,
    };

    enum RunState
    {
        Invalid,
        Prepared,
        Ready,
        Running,
        Complete,
    };

    cTkStackVector<GcDiscoverySearchConstraints::ConstraintBase *, 5> mConstraints;
    cTkVector<cGcDiscoveryRecord const *> mResult;
    cGcDiscoverySearch::RunState meRunState;
    unsigned int muMaxResults;
    cGcDiscoverySearch::SortMode meSortMode;
    bool mbIncludeHidden;
};

struct DiscoverySearchContext
{
    cGcDiscoverySearch *mpCurrentSearch;
    cTkVector<cGcDiscoveryRecord const *> mRecordsToSort;
    cGcDiscoveryStoreImpl<DefaultDiscoveryDataHashing, 19>::ConstIterator *mpIterator;
};

SKYSCRAPER_END