#pragma once

#include <skyscraper.h>

#include <toolkit/graphics/2d/ngui/TkNGuiTextEdit.h>

SKYSCRAPER_BEGIN

class cGcTextChatInput
{
    struct SCommandLookup
    {
        const char *mpcCommandName;
        const char *mpcShortCommandName;
    };

    cTkNGuiTextEditState mEditText;
    cTkFixedString<1023, char> msText;
    cTkFixedString<1023, char> msInputTextDisplayString;
    bool mbTextInputActive;
    bool mbWaitingForNoKeyboardInput;
    bool mbButtonReleased;
    unsigned char meCurrentCommand[1];
    unsigned char mePendingCommand[1];
    const cGcTextChatInput::SCommandLookup *mpLookupTable;
};

SKYSCRAPER_END