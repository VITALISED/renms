#pragma once
#include <metadata/metadata_common.h>
enum eNGuiForcedStyle
{
    ENGuiForcedStyle_None = 0,
    ENGuiForcedStyle_Default = 1,
    ENGuiForcedStyle_Highlight = 2,
    ENGuiForcedStyle_Active = 3,
}

class cTkNGuiForcedStyle
{
    static unsigned long long muNameHash = 0xB90A6A8C6ACFE0BC;
    static unsigned long long muTemplateHash = 0x9BEB641914C9DFD6;

    eNGuiForcedStyle NGuiForcedStyle;
}
