#pragma once

#include <skyscraper.h>
#include <application/states/GcApplicationState.h>

SKYSCRAPER_BEGIN

class cGcApplicationGalacticMapState : public cGcApplicationState
{
    bool mabMoveActive[2];
    cTkMatrix34 maMoveOrigin[2];
    bool mbRequestNextGalaxy;
    bool mbMultiplayer;
};

SKYSCRAPER_END