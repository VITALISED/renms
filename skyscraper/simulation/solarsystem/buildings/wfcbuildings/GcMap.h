#pragma once

#include <skyscraper.h>
#include <queue>
#include <toolkit/maths/numeric/TkTuple.h>

SKYSCRAPER_BEGIN

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
    std::vector<sFreighterRoom,TkSTLAllocatorShim<sFreighterRoom,8,-1> > maRooms;
};

SKYSCRAPER_END