/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <skyscraper.h>

#include <graphics/ngui/GcNGuiElement.h>

#include <graphics/ngui/metadata/gcnguitextdata.meta.h>
#include <toolkit/ngui/tknguigraphicstyledata.meta.h>
#include <toolkit/ngui/tknguitextstyledata.meta.h>

SKYSCRAPER_BEGIN

class cGcNGuiText : cGcNGuiElement
{
    cTkFixedString<128, char> mLocBlinkText;
    cTkNGuiTextStyleData mPreviousTextStyle;
    cTkNGuiGraphicStyleData mPreviousGraphicStyle;
    cGcNGuiTextData *mpTextData;
    unsigned __int64 miLocTextBlinkBaseTime;
};

SKYSCRAPER_END