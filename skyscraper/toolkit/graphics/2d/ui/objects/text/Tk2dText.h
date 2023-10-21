#pragma once

#include <skyscraper.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <toolkit/graphics/2d/ui/objects/text/styles/TkTextStyle.h>

SKYSCRAPER_BEGIN

class cTk2dText : public cTk2dObject
{
    const cTkTextStyle *mpTextStyle;
    const wchar_t *mpacText;
    cTkFont *mpFont;
    float mfTextHeight;
    int miStringLength;
    cTk2dText::ETextFormat meFormat;
    cTkVector2 mvParagraphAlignment;
    bool mbEnableHighlight;
};

SKYSCRAPER_END