/**
 * @file GcSimulationGlobals.h
 * @author VITALISED & Contributors
 * @since 2024-01-12
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

#include <toolkit/data/TkMetaDataClasses.h>

#include <simulation/components/utils/gcmultitoolpooldata.meta.h>

SKYSCRAPER_BEGIN

class cGcSimulationGlobals
{
  public:
    inline cGcSimulationGlobals() {}
    static cGcSimulationGlobals *GetInstance();

    cTkFixedString<128, char> macStartingSceneFile;
    cTkDynamicArray<cGcMultitoolPoolData> maMultitoolPool;
    uint64_t mu64ProceduralBuildingsGenerationSeed;
    cTkFixedString<128, char> macSpaceStationFile;
    cTkFixedString<128, char> macNexusFile;
    cTkFixedString<128, char> macNexusExteriorFile;
    cTkFixedString<128, char> macPlaceMarkerFile;
    cTkFixedString<128, char> macAbandonedSpaceStationFile;
    cTkFixedString<128, char> macPirateSystemSpaceStationFile;
    cTkDynamicArray<cTkFixedString<128, char>> maacBlackHoleAnomalies;
    cTkDynamicArray<cTkFixedString<128, char>> maacAtlasStationAnomalies;
    cTkFixedString<128, char> macNone;
    cTkFixedString<128, char> macPlacementDroneFile;
    cTkFixedString<128, char> macHeavyAirCave;
    cTkFixedString<128, char> macHeavyAirUnderwater;
    cTkFixedString<128, char> macHeavyAirAbandonedFreighter;
    cTkFixedString<128, char> macHeavyAirSpaceStorm;
    cTkDynamicArray<cTkFixedString<128, char>> maacPrefetchScenegraphResources;
    cTkDynamicArray<cTkFixedString<128, char>> maacPrefetchMaterialResources;
    cTkFixedString<128, char> macPlanetAtmosphereFile;
    cTkFixedString<128, char> macPlanetAtmosphereMaterialFile;
    cTkFixedString<128, char> macPlanetRingFile;
    cTkFixedString<128, char> macPlanetRingMaterialFile;
    cTkFixedString<128, char> macPlanetMaterialFile;
    cTkFixedString<128, char> macPlaterWaterMaterialFile;
    cTkDynamicArray<cTkFixedString<128, char>> maacPlanetTerrainMaterials;
    cTkDynamicArray<cTkFixedString<128, char>> maacPrefetchTextureResources;
    float mfWarpTunnelScale;
    cTkFixedString<128, char> macWarpTunnelFile;
    cTkFixedString<128, char> macBlackHoleTunnelFile;
    cTkFixedString<128, char> macTeleportTunnelFile;
    cTkFixedString<128, char> macPortalTunnelFile;
    cTkFixedString<128, char> macPortalStoryTunnelFile;
};

SKYSCRAPER_END