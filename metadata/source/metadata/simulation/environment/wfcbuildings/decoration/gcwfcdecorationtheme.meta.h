#pragma once
#include <metadata/metadata_common.h>
enum eWFCDecorationTheme
{
    EWFCDecorationTheme_Default = 0,
    EWFCDecorationTheme_Construction = 1,
}

class cGcWFCDecorationTheme
{
    static unsigned long long muNameHash = 0x9634E2763C4B5D4D;
    static unsigned long long muTemplateHash = 0x45C7C9E0AD9B71DD;

    eWFCDecorationTheme WFCDecorationTheme;
}
