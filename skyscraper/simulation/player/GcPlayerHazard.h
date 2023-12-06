/**
 * @file GcPlayerHazard.h
 * @author VITALISED & Contributors
 * @since 2023-12-07
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

#include <toolkit/audio/wwise/TkAudioManagerWwise.h>/
#include <toolkit/maths/geometry/TkPhysRelVec3.h>
#include <toolkit/utilities/containers/TkBitArray.h>

#include <gamestate/gcinventoryelement.meta.h>
#include <simulation/player/gcplayerhazardtable.meta.h>
#include <simulation/player/gcplayerhazardtype.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerHazard
{
  public:
    cGcPlayerHazardTable *mpHazardTable;
    cTkBitArray<unsigned int, 1, 32> mxHazardsActive;
    eHazard meHazardOverride;
    float mfHazardOverrideTarget;
    float mfHazardOverrideStrength;
    float mfLastHazardOverrideTime;
    cTkPhysRelVec3 mHazardOverridePosition;
    std::array<float, 6> mafHazardTimers;
    std::array<float, 6> mafHazardStateChangeTimes;
    std::array<int, 6> maiHazardChargeLastValues;
    std::array<float, 6> mafHazardLastPainTime;
    float mfLastWarningTime;
    float mfLastRestoreTime;
    std::array<cGcInventoryElement const *, 6> mapActiveShieldingItems;
    std::array<float, 6> mafLastEnergyDrainTime;
    std::array<bool, 6> mabTakenInitialHazardDamage;
    TkAudioObject mHazardAudioObject;
    TkAudioID mCurrentHazardAudioSwitch;
    bool mbHazardProtectionAudioLoopPlaying;
    cTkVector<std::pair<cGcInventoryElement const *, float>> mapActiveShieldingItemQueues[6];
};

SKYSCRAPER_END