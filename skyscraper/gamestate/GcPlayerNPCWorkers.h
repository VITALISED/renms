#pragma once

#include <skyscraper.h>
#include <gamestate/basebuilding/BaseIndex.h>
#include <toolkit/simulation/TkSeed.h>
#include <metadata/source/utilities/data/gcresourceelement.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerNPCWorkers
{
    struct WorkerStationInfo
    {
        bool mbWorkerHired;
        BaseIndex muWorkerIndex;
        cGcResourceElement mWorkerResourceData;
        cTkSeed mNPCInteractionSeed;
    };
};

SKYSCRAPER_END