/**
 * @file GcNetworkComponent.h
 * @author VITALISED & Contributors
 * @since 2024-01-01
 *
 * Copyright (C) 2024  VITALISED & Contributors
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

#include <toolkit/simulation/components/TkComponent.h>
#include <toolkit/utilities/containers/TkStackContainer.h>

SKYSCRAPER_BEGIN

class cGcNetworkComponent : public cTkComponent
{
  public:
    struct sSurvey
    {
        uint8_t *mpResponses;
        uint16_t maResponseBytes[31];
        uint16_t muResponses;
        uint16_t muRespondents;
        uint16_t mSurveyHandle;
        float mfStartTime;
    };

    cTkStackVector<cGcNetworkComponent::sSurvey, 4> mSurveys;
    uint16_t muSurveyIndexer;
};

SKYSCRAPER_END