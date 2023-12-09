/**
 * @file GcTelemetryManager.h
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

#include <gamestate/GcGameAnalytics.h>
#include <gamestate/GcStatsManager.h>

SKYSCRAPER_BEGIN

class cGcTelemetryManager : IStatVariantWatcher
{
  public:
    robin_hood::detail::Table<
        true, 80, TkID<128>, cGcStatDefinition const *, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>
        mStatDefinitionLookup;
    robin_hood::detail::Table<true, 80, TkID<128>, Stat, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>
        mStats;
    cTkVector<TkID<128>> mStatChangesSinceLastSave;
    robin_hood::detail::Table<true, 80, TkID<128>, int, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>
        mMissionStagesCached;
    robin_hood::detail::Table<true, 80, TkID<128>, int, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>
        mLevelledStatStagesCached;
    robin_hood::detail::Table<true, 80, TkID<128>, int, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>
        mStatStagesCached;
    cGcStatsManager *mpStatsManager;
    cGcGameAnalytics *mpGameAnalytics;
    float mfUpdateTimer;
    int miPlayerCount;
    int miMaxFullPlayerCount;
    int miMaxOrbPlayerCount;
    bool mbFullMultiplayer;
    uint64_t muPlayTime;
};

SKYSCRAPER_END