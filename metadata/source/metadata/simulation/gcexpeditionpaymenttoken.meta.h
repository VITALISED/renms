#pragma once
#include <metadata/metadata_common.h>

class cGcExpeditionPaymentToken
{
    static unsigned long long muNameHash = 0xF4416360D2B155D6;
    static unsigned long long muTemplateHash = 0x25EF5B34653E792A;

    TkID<128> mTokenName;
    int miTokenValue;
}
