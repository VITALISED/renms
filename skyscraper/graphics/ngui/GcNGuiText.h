#pragma once

#include <skyscraper.h>
#include <graphics/ngui/GcNGuiElement.h>
#include <metadata/ngui/tknguitextstyledata.meta.h>
#include <metadata/ngui/tknguigraphicstyledata.meta.h>
#include <metadata/graphics/ngui/metadata/gcnguitextdata.meta.h>

SKYSCRAPER_BEGIN

class cGcNGuiText : cGcNGuiElement
{
    cTkFixedString<128,char> mLocBlinkText;
    cTkNGuiTextStyleData mPreviousTextStyle;
    cTkNGuiGraphicStyleData mPreviousGraphicStyle;
    cGcNGuiTextData *mpTextData;
    unsigned __int64 miLocTextBlinkBaseTime;
};

SKYSCRAPER_END