#pragma once

#include <skyscraper.h>

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
};

SKYSCRAPER_END