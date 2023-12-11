/**
 * @file GcMap.h
 * @author VITALISED & Contributors
 * @since 2023-12-11
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

#include <toolkit/maths/numeric/TkTuple.h>
#include <toolkit/simulation/TkSeed.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <simulation/environment/wfcbuildings/gcfreighterbaseroom.meta.h>

SKYSCRAPER_BEGIN

class cGcSlot;
class cGcModuleSet;
class cGcMapLayout;

struct sFreighterRoom
{
    const cGcFreighterBaseRoom *mpRoom;
    cTkVector<cGcSlot const *> maSlots;
};

class cGcMap
{
    const cTkIntTuple3<int> mSize;
    cGcModuleSet *mModuleSet;
    const bool mbSymmetric;
    const bool mbImprovedCoherence;
    const cGcMapLayout *const mpLayout;
    cGcSlot **mpaSlots;
    std::queue<cGcSlot *> mConstraintPropagationQueue;
    cTkSeed mSeed;
    cTkSeed mFallbackSeed;
    cTkVector<sFreighterRoom> maRooms;
};

SKYSCRAPER_END