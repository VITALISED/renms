#pragma once
#include <metadata/metadata_common.h>

class cGcPunctuationDelay
{
    static unsigned long long muNameHash = 0x88FA9D134F35E97B;
    static unsigned long long muTemplateHash = 0x18FCA1B628A26A1D;

    cTkFixedString<32,char> macPunctuation;
    float mfDelay;
}
