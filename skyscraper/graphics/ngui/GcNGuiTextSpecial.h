#pragma once

#include <skyscraper.h>
#include <toolkit/system/TkMemoryManager.h>
#include <graphics/ngui/GcNGuiText.h>
#include <graphics/ngui/GcNGuiStyledString.h>

SKYSCRAPER_BEGIN

class cGcNGuiTextSpecial : public cGcNGuiText
{
    cGcNGuiStyledString::StyledStringLayout mStyledStringLayout;
    std::basic_string<char,std::char_traits<char>, TkSTLAllocatorShim<char> > msDisplayString;
    bool mbBigString;
    bool mbUpdateLayout;
};

SKYSCRAPER_END