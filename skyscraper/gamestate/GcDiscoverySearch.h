#pragma once

#include <skyscraper.h>

#include <atlas/WinHttpTask.h>
#include <gamestate/GcDiscoveryRecord.h>
#include <gamestate/GcDiscoverySearchConstraints.h>
#include <toolkit/system/memory/pools/TkMemoryPool.h>
#include <toolkit/utilities/containers/TkStackVector.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cGcDiscoverySearch : AutoPooled<19>
{
    typedef WinHttpTask::State::Enum RunState;

    enum SortMode
    {
        Unsorted,
        TimestampOldestFirst,
        TimestampNewestFirst,
    };

    cTkStackVector<GcDiscoverySearchConstraints::ConstraintBase *> mConstraints;
    cTkVector<cGcDiscoveryRecord const *> mResult;
    cGcDiscoverySearch::RunState meRunState;
    unsigned int muMaxResults;
    cGcDiscoverySearch::SortMode meSortMode;
    bool mbIncludeHidden;
};

SKYSCRAPER_END