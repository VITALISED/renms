/**
 * @file GcMapLayout.h
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

#include <simulation/solarsystem/buildings/wfcbuildings/GcWFCScenes.h>
#include <toolkit/maths/numeric/TkTuple.h>

SKYSCRAPER_BEGIN

class cGcModule;
class cGcModuleSet;

struct sModulePreset
{
    cGcModule *mModule;
    const cTkIntTuple3<int> mPosition;
};

class cGcMapLayout
{
  public:
    const cGcModuleSet *mModuleSet;
    const float mfRelativeProbability;
    cGcWFCScene mScene;
    cTkVector<sModulePreset> mModulePresets;
    cTkVector<cTkIntTuple3<int>> mSlotsWithDecorationDisabled;
    cTkVector<cTkIntTuple3<int>> mNonWalkableSlots;
    cTkIntTuple3<int> mWFCStartPosition;
    bool mbHasWFCStartPosition;
    cTkIntTuple3<int> mSize;
    bool mbSymmetric;
    bool *mapActiveSlots;
    cTkSmartResHandle mResHandle;
    bool mbHasFinishedParsing;
};

SKYSCRAPER_END