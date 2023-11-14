#pragma once

#include <skyscraper.h>

#include <gamestate/GcWonderManager.h>
#include <graphics/frontend/pages/data/TextScrollBarState.h>
#include <simulation/player/GcPlayerEmoteProp.h>

SKYSCRAPER_BEGIN

class cGcCustomWonderTextEntryHandler
{
    typedef cGcPlayerEmoteProp::eState eState;

    cGcCustomWonderTextEntryHandler::eState meState;
    cGcWonderHandle mWonder;
};

class cGcWikiPageData
{
    int miCurrentCategoryIdx;
    int miCurrentTopic;
    int miCurrentTopicPage;
    int miCurrentPage;
    float mfTimeSinceLastTransition;
    TextScrollBarState mTextScrollBarState;
    cGcCustomWonderTextEntryHandler mCustomWonderTextEntryHandler;
};

SKYSCRAPER_END