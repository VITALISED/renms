#pragma once

#include <skyscraper.h>

#include <stb_textedit.h>
#include <toolkit/graphics/2d/ngui/TkNGuiElementID.h>
#include <toolkit/utilities/TkString.h>

SKYSCRAPER_BEGIN

struct cTkNGuiTextEditState
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