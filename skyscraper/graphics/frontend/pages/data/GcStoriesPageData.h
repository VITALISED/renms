#pragma once

#include <skyscraper.h>

#include <graphics/frontend/pages/data/TextScrollBarState.h>
#include <toolkit/utilities/TkArray.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cGcStoriesPageData
{
    struct sGcUnlockedStoryInfo
    {
        cTkDynamicArray<int> maiUnlockedBranch;
        int miUnlockedIdx;
        bool mbIdxIsBitmask;
        bool mbSeenLastEntry;
    };

    int miCurrentCategory;
    int miCurrentTopicPage;
    int miCurrentStoryPage;
    int miCurrentStoryPageSection;
    cTkVector<cTkFixedString<8192, char>> maCurentPageSecionsText;
    float mfTimeSinceLastTransition;
    cTkFixedArray<cTkDynamicArray<cGcStoriesPageData::sGcUnlockedStoryInfo>, 8> maiUnlockedStoryIndex;
    cTkFixedArray<int, 8> maiCategoryUnseenCount;
    TextScrollBarState mTextScrollBarState;
};

SKYSCRAPER_END