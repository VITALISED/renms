#pragma once

#include <skyscraper.h>
#include <atlas/GcAtlasBrokerAuth.h>

SKYSCRAPER_BEGIN

class cGcNetworkConstants
{
public:
    typedef cGcAtlasBrokerAuth::State::Constants TransmissionChannels;
    typedef cGcAtlasBrokerAuth::State::Constants PlayerMovementState;

    enum LobbyType
    {
        Gameplay,
        Fireteam,
        NumLobbyTypes,
    };
};

SKYSCRAPER_END