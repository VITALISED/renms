#pragma once

#include <skyscraper.h>
#include <graphics/ngui/GcNGuiElement.h>
#include <metadata/toolkit/ngui/tknguitextstyledata.meta.h>
#include <metadata/toolkit/ngui/tknguigraphicstyledata.meta.h>
#include <metadata/source/graphics/ngui/metadata/gcnguitextdata.meta.h>

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