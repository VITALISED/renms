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

    enum OnlinePlatformType
    {
        Generic,
        GOG,
        PlayStation,
        Steam,
        XboxLive,
        GenericKBM,
        Nintendo,
        NumOnlinePlatformTypes = 7,
    };
};

SKYSCRAPER_END