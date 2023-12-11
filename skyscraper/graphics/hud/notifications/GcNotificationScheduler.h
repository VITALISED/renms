/**
 * @file GcNotificationScheduler.h
 * @author VITALISED & Contributors
 * @since 2023-12-10
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
#include <toolkit/utilities/containers/TkUnorderedMap.h>

#include <simulation/missions/gcmissiontable.meta.h>
#include <simulation/missions/scheduling/gcmissioncommunitydata.meta.h>
#include <simulation/missions/scheduling/gcmissionschedulestable.meta.h>

SKYSCRAPER_BEGIN

class cGcNotificationScheduler
{
  public:
    struct MissionSchedulingData
    {
        const cGcMissionSchedulingData *mMissionSchedulingData;
        uint64_t mStartDateAsEpoch;
        uint64_t mEndDateAsEpoch;
    };

    const cGcMissionTable *mpRecurringMissionTable;
    const cGcMissionCommunityData *mpCommunityData;
    const cGcMissionSchedulesTable *mpSchedulesTable;
    cTkUnorderedMap<TkID<128>, cGcNotificationScheduler::MissionSchedulingData, TkIDUnorderedMap::Hash128>
        mMissionIDToSchedulingData;
    cTkUnorderedMap<TkID<128>, uint64_t, TkIDUnorderedMap::Hash128> mMissionIDToRecurrenceDeadline;
    cGcAtlasCommunityData mCachedAtlasCommunityData;
    bool mbAtlasCommunityDataAvailable;
};

SKYSCRAPER_END