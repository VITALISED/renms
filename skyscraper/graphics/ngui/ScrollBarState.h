#pragma once

#include <skyscraper.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>

SKYSCRAPER_BEGIN

struct ScrollBarState
{
    int miNumEntries;
    int miCurrentStartIndex;
    int miEntriesPerPage;
    cTkVector2 mfLastSeenPos;
    cTkVector2 mfLastSeenSize;
};

SKYSCRAPER_END