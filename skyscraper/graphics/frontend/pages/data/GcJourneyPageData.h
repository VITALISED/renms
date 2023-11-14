#pragma once

#include <skyscraper.h>

#include <graphics/frontend/pages/data/TextScrollBarState.h>

#include <journey/gcjourney.meta.h>

SKYSCRAPER_BEGIN

class cGcJourneyPageData
{
    cGcJourney *mpJourney;
    TextScrollBarState mTextScrollBarState;
    int miCurrentCategory;
    int miCategoriesCount;
    float mfTimeSinceLastTransition;
    int miPinnedJourneyMilestone;
};

SKYSCRAPER_END