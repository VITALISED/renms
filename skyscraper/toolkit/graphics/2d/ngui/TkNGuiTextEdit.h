/**
 * @file TkNGuiTextEdit.h
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

#include <stb_textedit.h>
#include <toolkit/graphics/2d/ngui/TkNGuiElementID.h>
#include <toolkit/utilities/TkString.h>

SKYSCRAPER_BEGIN

class cTkNGuiEditor;

class cTkNGuiTextEditState
{
    VFT<1> *__vftable;
    cTkFixedString<512, char> macEditedText;
    cTkFixedString<512, char> macInitialText;
    cTkFixedString<512, char> macShelvedTextEdit;
    cTkNGuiElementID mShelvedEditID;
    float mfWidth;
    float mfScrollX;
    float mfInitTime;
    float mfNavigateTime;
    STB_TexteditState *mpStbState;
    bool mbDoubleClicked;
    cTkNGuiEditor *mpGui;
};

SKYSCRAPER_END