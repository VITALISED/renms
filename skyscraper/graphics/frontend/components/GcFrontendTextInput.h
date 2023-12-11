/**
 * @file GcFrontendTextInput.h
 * @author VITALISED & Contributors
 * @since 2023-12-10
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

#include <toolkit/graphics/2d/ngui/TkNGuiTextEdit.h>

SKYSCRAPER_BEGIN

enum FrontendTextInputState : __int32
{
    EFrontendTextInputState_Free,
    EFrontendTextInputState_WaitingForText,
    EFrontendTextInputState_TextReady,
    EFrontendTextInputState_ProfanityChecking,
    EFrontendTextInputState_ProfanityChecked,
};

class cGcFrontendTextInput
{
  public:
    cTkNGuiTextEditState mTextEditState;
    FrontendTextInputState meTextInputState;
    cTkFixedString<64, char> msTitle;
    cTkFixedString<64, char> msPlaceholder;
    cTkFixedString<64, wchar_t> msTitleWide;
    cTkFixedString<64, wchar_t> msPlaceholderWide;
    cTkFixedString<256, wchar_t> msInputStringUTF16;
    cTkFixedString<256, char> msTextInputString;
    bool mbUsingDefaultInput;
    bool mbWaitingForNoKeyboardInput;
    bool mbProfanityFilter;
    bool mbIsNaughty;
    unsigned int miMaxCharacters;
    bool mbTextEntryFinished;
};

SKYSCRAPER_END