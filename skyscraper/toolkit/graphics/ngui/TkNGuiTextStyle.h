#pragma once

#include <skyscraper.h>
#include <metadata/ngui/tknguitextstyledata.meta.h>

SKYSCRAPER_BEGIN

class cTkNGuiTextStyle
{
    cTkNGuiTextStyleData mDefault;
    cTkNGuiTextStyleData mHighlight;
    cTkNGuiTextStyleData mActive;
};

SKYSCRAPER_END