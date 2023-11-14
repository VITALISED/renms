#pragma once

#include <skyscraper.h>

#include <toolkit/graphics/TkColour.h>

SKYSCRAPER_BEGIN

class cGcMarkerRenderData
{
    cTkColour mFillColour;
    cTkColour mBackgroundColour;
    float mfAmount;
    float mfInnerRadius;
    float mfOuterRadius;
};

SKYSCRAPER_END