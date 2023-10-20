#pragma once
#include <metadata/metadata_common.h>

class cGcBlockedMessage
{
    static unsigned long long muNameHash = 0xD51346A323488A3E;
    static unsigned long long muTemplateHash = 0xCFCB61BDC2999525;

    cTkFixedString<128,char> macMessageId;
}
