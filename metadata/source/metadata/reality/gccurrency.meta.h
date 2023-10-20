#pragma once
#include <metadata/metadata_common.h>
enum eCurrency
{
    ECurrency_Units = 0,
    ECurrency_Nanites = 1,
    ECurrency_Specials = 2,
}

class cGcCurrency
{
    static unsigned long long muNameHash = 0x17AE5B83C6E9DF12;
    static unsigned long long muTemplateHash = 0x80368A509B1B150A;

    eCurrency Currency;
}
