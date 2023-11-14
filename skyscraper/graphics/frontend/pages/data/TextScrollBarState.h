#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

struct TextScrollBarState
{
    float mfCurrentScrollOffsetPercentage;
    float mfTextOnScreenPercentage;
    int miCurrentPage;
    int miMaxPageIndex;
    bool mbInactive;
    bool mbFirstUpdateAfterReset;
    bool mbMoveToPreviousPage;
    bool mbMoveToNextPage;
    bool mbNewTextSet;
    bool mbForceScrollToBottom;
};

SKYSCRAPER_END