/**
 * @file GcModule.h
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

#include <simulation/solarsystem/buildings/wfcbuildings/GcModuleSubset.h>
#include <simulation/solarsystem/buildings/wfcbuildings/GcWFCScenes.h>
#include <toolkit/core/types/TkID.h>
#include <toolkit/utilities/containers/TkBitArray.h>

#include <simulation/environment/wfcbuildings/decoration/gcwfcdecorationitem.meta.h>

SKYSCRAPER_BEGIN

class cGcModuleSet;

class cGcModule
{
  public:
    cGcModuleSet *mModuleSet;
    const int miIndex;
    const int miModuePrototypeIndex;
    const eBlockRotation meRotation;
    const float mfRelativeProbability;
    const float mfPLogP;
    const bool mbWalkable;
    const cTkBitArray<uint64_t, true, 128> maConnectors[6];
    const int miNextRotationIndex;
    const TkID<128> mLayoutGroup;
    cGcWFCScenes mGeometry;
    cGcModuleSubset maPossibleNeighbours[6];
    uint8_t miRequireAboveTerrain;
    uint8_t miRequireBelowTerrain;
    cGcModuleSubset mSymmetricPartners;
    cTkVector<cGcWFCDecorationItem const *> mapDecorationItems[2];
};

SKYSCRAPER_END