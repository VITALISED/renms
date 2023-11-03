#pragma once

#include <skyscraper.h>
#include <queue>
#include <simulation/solarsystem/buildings/wfcbuildings/GcModuleSet.h>
#include <simulation/solarsystem/buildings/wfcbuildings/GcMapLayout.h>
#include <toolkit/maths/numeric/TkTuple.h>
#include <metadata/source/simulation/environment/wfcbuildings/gcfreighterbaseroom.h>

SKYSCRAPER_BEGIN

struct sFreighterRoom
{
    const cGcFreighterBaseRoom *mpRoom;
    cTkVector<cGcSlot const *> maSlots;
};


class cGcMap
{
    const cTkIntTuple3<int> mSize;
    cGcModuleSet *mModuleSet;
    const bool mbSymmetric;
    const bool mbImprovedCoherence;
    const cGcMapLayout *const mpLayout;
    cGcSlot **mpaSlots;
    std::queue<cGcSlot *> mConstraintPropagationQueue;
    cTkSeed mSeed;
    cTkSeed mFallbackSeed;
    cTkVector<sFreighterRoom> maRooms;
};

SKYSCRAPER_END