/**
 * @file Tk2dText.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <skyscraper.h>

#include <toolkit/graphics/2d/ui/font/TkFont.h>
#include <toolkit/graphics/2d/ui/objects/Tk2dObject.h>
#include <toolkit/graphics/2d/ui/objects/text/styles/TkTextStyle.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>

SKYSCRAPER_BEGIN

class cTk2dText : public cTk2dObject
{
  public:
    enum ETextFormat
    {
        eParagraph,
        eSentence,
    };

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