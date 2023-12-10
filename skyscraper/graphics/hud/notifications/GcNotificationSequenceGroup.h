/**
 * @file GcNotificationSequenceGroup.h
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

#include <graphics/2d/GcSlotIcon.h>

#include <simulation/missions/sequences/gcmissionsequencegroup.meta.h>

SKYSCRAPER_BEGIN

class cGcNotificationSequenceGroup
{
  public:
    cGcMissionSequenceGroup *mpData;
    cGcSlotIcon mIcon;

    virtual ~cGcNotificationSequenceGroup();
    virtual void GetObjective(cTkFixedString<128, char> *);
    virtual void GetObjectiveTip(cTkFixedString<1024, char> *);
    virtual TkID<128> *GetTargetMissionSurveyId(TkID<128> *result);
    virtual bool GetTargetMissionSurveyDefinitelyExists();
    virtual TkID<128> *GetPinnedMissionBuildTarget(TkID<128> *result);
};

SKYSCRAPER_END