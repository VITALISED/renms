/**
 * @file GcStatsManager.h
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

#include <networking/GcNetworkRpcCall.h>

#include <gamestate/stats/gcjourneymilestonetable.meta.h>
#include <gamestate/stats/gcleveledstattable.meta.h>
#include <gamestate/stats/gcstatdefinitiontable.meta.h>
#include <gamestate/stats/gcstatgrouptable.meta.h>

SKYSCRAPER_BEGIN

class IStatWatcher
{
  public:
    virtual void StatChanged(const TkID<128> *, long double);
    virtual void StatChanged(const TkID<128> *, int64_t);
};

class IStatVariantWatcher
{
    virtual void VariantChanged(const TkID<128> *, const cGcStatDefinition *, Stat::AvgStat);
    virtual void VariantChanged(const TkID<128> *, const cGcStatDefinition *, float);
    virtual void VariantChanged(const TkID<128> *, const cGcStatDefinition *, int);
};

struct Stat
{
  public:
    struct AvgStat
    {
        float mfAvgNumerator;
        float mfAvgDenominator;
    };

    union StatValue {
        int miValue;
        float mfValue;
        Stat::AvgStat mAvgValue;
    };
    Stat::StatValue mValue;
};

struct StatListener
{
    uint64_t mListenerAddress;
    TkID<128> mId;
    robin_hood::detail::Table<true, 80, TkID<128>, Stat, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>
        mStats;
    IStatVariantWatcher *mpVariantWatcher;
};

class cGcStatsManager
{
  public:
    cGcRpcCallBase *RSRI;
    cGcRpcCallBase *RSRF;
    cGcStatDefinitionTable *mpStatDefinitionsTable;
    cGcStatGroupTable *mpStatGroupsTable;
    cGcLeveledStatTable *mpLeveledStatTable;
    cGcJourneyMilestoneTable *mpJourneyMilestoneTable;
    robin_hood::detail::Table<
        true, 80, TkID<128>, cGcStatDefinition *, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>
        mStatDefinitionLookup;
    cTkVector<TkID<128>> mStatChangesThisFrame;
    cTkVector<TkID<128>> mStatChangesSinceLastSave;
    cTkVector<TkID<128>> mLevelledStatChangesSinceLastSave;
    cTkVector<StatListener> mStatListeners;
    cTkVector<int> mActiveListenerIndicies;
    cTkSmartResHandle mStatLevelIcons[11];
    robin_hood::detail::Table<
        true, 80, TkID<128>, cTkVector<IStatWatcher *> *, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128>>>
        mStatWatchers;
    cTkVector<IStatWatcher *> mVariantStatWatchers;
};

SKYSCRAPER_END