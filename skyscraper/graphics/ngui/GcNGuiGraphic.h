#pragma once

#include <skyscraper.h>
#include <graphics/ngui/GcNGuiElement.h>
#include <metadata/source/graphics/ngui/metadata/gcnguigraphicdata.meta.h>

SKYSCRAPER_BEGIN

class cGcNGuiGraphic : public cGcNGuiElement
{
  cGcNGuiGraphicData *mpGraphicData;
  cTkNGuiGraphicStyleData mPreviousGraphicsStyle;
};

SKYSCRAPER_END