/**
 * @file GcSeasonPageData.h
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

#include <toolkit/utilities/containers/TkVector.h>

#include <graphics/ngui/metadata/gcnguispecialtextstyledata.meta.h>

SKYSCRAPER_BEGIN

class cGcSeasonPageData
{
  public:
    int miExpeditionDistance;
    int miSystemsDiscovered;
    float mfDistanceWalked;
    int miNanites;
    int miMoney;
    cTkVector<float> mafInitialRingPositions;
    cTkVector<float> mafInitialStarPositions;
    cTkVector<float> mafInitialStarSizes;
    cGcNGuiSpecialTextStyleData *mpProgressStyleData;
    long double mfStageChangeStartTime;
    long double mfStageChangeTime;
    int miPreviousStageIndex;
    int miStageIndex;
    int miNextStageIndex;
    bool mbShowingLatestStage;
    int mbShowingFinalStage;
};

SKYSCRAPER_END