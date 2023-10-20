#pragma once
#include <metadata/metadata_common.h>

class cGcDeathQuote
{
    static unsigned long long muNameHash = 0xBCF143B353D06CD3;
    static unsigned long long muTemplateHash = 0xEC3FF810BBEE79F9;

    cTkFixedString<128,char> macQuoteLine1;
    cTkFixedString<128,char> macQuoteLine2;
    cTkFixedString<32,char> macAuthor;
}
