#pragma once

#include <skyscraper.h>
#include <atlas/WinHttpTask.h>
#include <toolkit/simulation/TkSeed.h>
#include <simulation/galaxy/GcGalacticVoxelCoordinate.h>

SKYSCRAPER_BEGIN

struct SystemSeed
{
    unsigned __int64 mu64Hash1;
    unsigned __int64 mu64Hash2;
};

class cGcFirstBootContext
{
    typedef WinHttpTask::State::Enum State;

    enum GenerationMode
    {
        Random,
        BlackHoleDestination,
        StoryPortalPlanet,
    };

    cGcFirstBootContext::State meState;
    cGcFirstBootContext::GenerationMode meGenerationMode;
    SystemSeed mSystemSeed;
    cTkSeed mStarSeed;
    cGcGalacticVoxelCoordinate mBootCoordinate;
    int miDestinationIndex;
    unsigned __int64 mResultSpawnUA;
};

SKYSCRAPER_END