#pragma once

#include <skyscraper.h>
#include <toolkit/graphics/2d/ui/font/TkFont.h>
#include <toolkit/graphics/TkColour.h>
#include <toolkit/graphics/2d/ui/objects/text/styles/TkTextStyle.h>

SKYSCRAPER_BEGIN

class cTk2dTextPreset
{
    float mfTextHeight;
    cTkFont *mpFont;
    cTkColour mColour;
    const cTkTextStyle *mpTextStyle;
    bool mbEnableHighlight;
};

SKYSCRAPER_END