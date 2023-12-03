#pragma once

#include <skyscraper.h>

#include <gamestate/gcplayerspawnstatedata.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerRespawn
{
  public:
    enum RespawnReason
    {
        FreshStart,
        LoadSave,
        LoadToLocation,
        RestorePreviousSave,
        DeathInSpace,
        DeathOnPlanet,
        DeathInOrbit,
        DeathOnAbandonedFreighter,
        WarpInShip,
        Teleport,
        Portal,
        UpgradeSaveAfterPatch,
        SwitchAmbientPlanet,
        BaseViewerMode,
        WarpInFreighter,
        JoinMultiplayer,
    };

    cGcPlayerSpawnStateData mGeneratedPlayerSpawn;
    bool mbWasPlayerInShipWhenKilled;
    bool mbOverrideSpawnPlayerOnPlanet;
};

SKYSCRAPER_END