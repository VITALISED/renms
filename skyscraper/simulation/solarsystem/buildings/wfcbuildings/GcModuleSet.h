/**
 * @file GcModuleSet.h
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

#include <simulation/solarsystem/buildings/wfcbuildings/GcBuildingPreset.h>
#include <simulation/solarsystem/buildings/wfcbuildings/GcMap.h>
#include <simulation/solarsystem/buildings/wfcbuildings/GcMapLayout.h>
#include <simulation/solarsystem/buildings/wfcbuildings/GcModule.h>
#include <simulation/solarsystem/buildings/wfcbuildings/GcModuleSubset.h>
#include <simulation/solarsystem/buildings/wfcbuildings/GcSlot.h>

#include <gameplay/gcnpcplacementinfo.meta.h>
#include <simulation/environment/wfcbuildings/decoration/gcwfcdecorationitem.meta.h>
#include <simulation/environment/wfcbuildings/decoration/gcwfcdecorationset.meta.h>
#include <simulation/environment/wfcbuildings/gcwfcbuilding.meta.h>
#include <simulation/environment/wfcbuildings/gcwfcmoduleset.meta.h>

SKYSCRAPER_BEGIN

class cGcPlanet;

class cGcModuleSet
{
  public:
    struct sOptimizeTask
    {
        cGcMap mMap;
        cGcSlot *mCenterSlot;
        cTkVector<cGcModule *> mBoundaryOnlyModules;
        int miModulesOptimized;
    };

    const cTkFixedString<128, char> macFilename;
    const cTkVector3 mBlockSize;
    const int miSize;
    const cGcWFCModuleSet *mMetadata;
    const cGcWFCBuilding *const mpBuildingConfiguration;
    cGcModule **const mpaModules;
    robin_hood::detail::Table<
        false, 80, unsigned char, cGcModuleSubset, robin_hood::hash<unsigned char, void>, std::equal_to<unsigned char>>
        mModulesExcludedByTerrainPattern;
    robin_hood::detail::Table<
        true, 80, cGcWFCDecorationItem const *, cGcWFCScenes, robin_hood::hash<cGcWFCDecorationItem const *, void>,
        std::equal_to<cGcWFCDecorationItem const *>>
        mDecorationScenes;
    cGcModuleSubset maExcludedOnBoundary[6];
    cGcModuleSubset mSymmetricModules;
    cGcModuleSubset mWalkableModules;
    cTkVector<cGcModuleSubset> mGroundLevelModuleGroups;
    cTkVector<cGcNPCPlacementInfo const *> mNPCPlacementInfos;
    cGcWFCDecorationSet *mapDecorationSets[2];
    cTkVector<std::pair<cTkAABB, cTkMatrix34>> mDefaultBlockTerrainEdits;
    cTkVector<cGcMapLayout *> mLayouts;
    robin_hood::detail::Table<
        true, 80, cGcPlanet const *, int *, robin_hood::hash<cGcPlanet const *, void>, std::equal_to<cGcPlanet const *>>
        mBuildingPresetsByPlanet;
    cTkVector<cGcBuildingPreset *> mBuildingPresets;
    robin_hood::detail::Table<
        false, 80, cTkBitArray<uint64_t, true, 128>, cTkBitArray<uint64_t, true, 128>,
        robin_hood::hash<cTkBitArray<uint64_t, true, 128>, void>, std::equal_to<cTkBitArray<uint64_t, true, 128>>>
        mCompatibleConnectors;
    cGcModuleSet::sOptimizeTask *mpOptimizeTask;
};

SKYSCRAPER_END