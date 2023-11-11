#pragma once

#include <skyscraper.h>

#include <toolkit/graphics/2d/ngui/TkNGui.h>
#include <toolkit/utilities/TkString.h>

SKYSCRAPER_BEGIN

enum FrontendTextInputState
{
    EFrontendTextInputState_Free,
    EFrontendTextInputState_WaitingForText,
    EFrontendTextInputState_TextReady,
    EFrontendTextInputState_ProfanityChecking,
    EFrontendTextInputState_ProfanityChecked,
};

class cGcFrontendTextInput
{
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