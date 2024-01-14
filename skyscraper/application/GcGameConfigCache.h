/**
 * @file GcGameConfigCache.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
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

#include <gamestate/gcgamemode.meta.h>
#include <simulation/environment/gcplanetlife.meta.h>

SKYSCRAPER_BEGIN

enum eBootLoadDelay
{
    EBootLoadDelay_LoadAll,
    EBootLoadDelay_WaitForPlanet,
    EBootLoadDelay_WaitForNothing,
    EBootLoadDelay_NumTypes,
};

enum eGameStateMode
{
    EGameStateMode_LoadPreset,
    EGameStateMode_UserStorage,
    EGameStateMode_FreshStart,
    EGameStateMode_NumTypes,
};

enum eSolarSystemBoot
{
    ESolarSystemBoot_FromSettings,
    ESolarSystemBoot_Generate,
    ESolarSystemBoot_NumTypes,
};

enum eBootMode
{
    EBootMode_MinimalSolarSystem,
    EBootMode_SolarSystem,
    EBootMode_GalaxyMap,
    EBootMode_SmokeTest,
    EBootMode_SmokeTestGalaxyMap,
    EBootMode_Scratchpad,
    EBootMode_UnitTest,
    EBootMode_NumTypes,
};

enum ePlayerSpawnLocationOverride
{
    EPlayerSpawnLocationOverride_None,
    EPlayerSpawnLocationOverride_FromSettings,
    EPlayerSpawnLocationOverride_Space,
    EPlayerSpawnLocationOverride_SpaceStation,
    EPlayerSpawnLocationOverride_RandomPlanet,
    EPlayerSpawnLocationOverride_GameStartPlanet,
    EPlayerSpawnLocationOverride_SpecificLocation,
    EPlayerSpawnLocationOverride_NumTypes,
};

class cGcGameConfigCache
{
  public:
    eBootLoadDelay meBootLoadDelay;
    bool mbSkipIntro;
    bool mbSkipPlanetDiscoverOnBoot;
    ePresetGameMode meNewSaveGameMode;
    int32_t miForceSaveSlot;
    bool mbForceLatestSaveSlot;
    bool mbSpawnPirates;
    bool mbSpawnRobots;
    bool mbSpawnShips;
    bool mbSpawnPulseEncounters;
    eLifeSetting meForceCreatureLifeLevelTo;
    bool mbForceCreatureLifeLevel;
    eGameStateMode meGameStateMode;
    eSolarSystemBoot meSolarSystemBoot;
    eBootMode meBootMode;
    ePlayerSpawnLocationOverride mePlayerLocationOverride;
    uint64_t mMultiplayerUAOverride;
    uint64_t mUDAOverride[2];
    uint64_t mUAOverride;
};

SKYSCRAPER_END