#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

struct TkHandle 
{
    union
    {
        struct
        {
            unsigned __int32 miLookup : 18;
            unsigned __int32 miIncrementor : 14;
        };
        unsigned int miLookupInt;
    };
};

SKYSCRAPER_END