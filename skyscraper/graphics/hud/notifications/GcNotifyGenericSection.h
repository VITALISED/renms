/**
 * @file GcNotifyGenericSection.h
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

#include <graphics/hud/notifications/conditions/GcNotificationConditions.h>
#include <graphics/hud/notifications/consequences/GcNotificationConsequences.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <simulation/missions/sequences/gcmissionsequencegroup.meta.h>

SKYSCRAPER_BEGIN

class cGcNotifyGenericSection
{
  public:
    cGcMissionSequenceGroup *mpGroupData;
    cTkFixedString<128, char> macName;
    int miStartIndex;
    int miEndIndex;
    eConditionTest meConditionTest;
    eRepeatLogic meRepeatLogic;
    bool mbForceConditionsTrue;
    cTkVector<cGcGenericSectionCondition *> mapConditions;
    cTkVector<cGcGenericSectionConsequence *> mapConsequences;

    virtual ~cGcNotifyGenericSection();
    virtual TkID<128> *GetTargetMissionSurveyId(TkID<128> *result);
    virtual bool GetTargetMissionSurveyDefinitelyExists();
};

SKYSCRAPER_END