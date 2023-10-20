#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/stats/gcjourneymilestonedata.meta.h>

class cGcJourneyMilestoneTable
{
    static unsigned long long muNameHash = 0xD2E65AA0EC314D9C;
    static unsigned long long muTemplateHash = 0xD134BF6FFEDA2E80;

    cTkDynamicArray<cGcJourneyMilestoneData> maGcJourneyMilestoneTable;
}
