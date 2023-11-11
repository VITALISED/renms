#pragma once

#include <skyscraper.h>

#include <toolkit/graphics/2d/ngui/TkNGuiElementData.h>
#include <toolkit/graphics/2d/ngui/TkNGuiInput.h>
#include <toolkit/maths/geometry/TkBBox2d.h>

SKYSCRAPER_BEGIN

class cTkNGui;

class cTkNGuiGraphicStyleEntry
{
    void (*mpRenderFunction)(cTkNGui *, void *, cTkBBox2d *, eNGuiInputType, cTkNGuiElementData *);
    void (*mpMarginFunction)(cTkNGui *, void *, float *, float *, float *, float *, cTkNGuiElementData *);
    void *mpData;
};

class cTkNGuiTextStyleEntry
{
    void (*mpRenderFunction)(cTkNGui *, void *, const char *, cTkBBox2d *, eNGuiInputType, cTkNGuiElementData *);
    void (*mpSizeFunction)(cTkNGui *, void *, const char *, const char *, float *, float *, cTkNGuiElementData *);
    void *mpData;
};

SKYSCRAPER_END