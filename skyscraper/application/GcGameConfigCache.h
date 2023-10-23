#pragma once

#include <skyscraper.h>
#include <metadata/gamestate/gcgamemode.meta.h>
#include <metadata/simulation/environment/gcplanetlife.meta.h>

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
    eBootLoadDelay meBootLoadDelay;
    bool mbSkipIntro;
    bool mbSkipPlanetDiscoverOnBoot;
    ePresetGameMode meNewSaveGameMode;
    int miForceSaveSlot;
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
    unsigned __int64 mMultiplayerUAOverride;
    unsigned __int64 mUDAOverride[2];
    unsigned __int64 mUAOverride;
};

SKYSCRAPER_END