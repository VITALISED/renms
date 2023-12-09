/**
 * @file GcUserSeenItemsState.h
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

#include <toolkit/core/types/TkID.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cGcUserSeenItemsState
{
  public:
    robin_hood::detail::Table<true, 80, TkID<256>, void, robin_hood::hash<TkID<256>, void>, std::equal_to<TkID<256>>>
        mSeenWikiTopics;
    robin_hood::detail::Table<true, 80, TkID<256>, void, robin_hood::hash<TkID<256>, void>, std::equal_to<TkID<256>>>
        mUnlockedWikiTopics;
    robin_hood::detail::Table<true, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>
        mSeenSubstances;
    robin_hood::detail::Table<true, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>
        mSeenTechnologies;
    robin_hood::detail::Table<true, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>
        mSeenProducts;
    robin_hood::detail::Table<true, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>
        mUnlockedTitles;
    robin_hood::detail::Table<true, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>
        mUnlockedSpecials;
    robin_hood::detail::Table<true, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>
        mUnlockedSeasonRewards;
    robin_hood::detail::Table<true, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>
        mUnlockedTwitchRewards;
    robin_hood::detail::Table<true, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>
        mUnlockedPlatformRewards;
    cTkVector<std::pair<void(__cdecl *)(void *), void *>> mDataLoadedCallbacks;
    bool mbOutdated;
    bool mbLoaded;
};

SKYSCRAPER_END