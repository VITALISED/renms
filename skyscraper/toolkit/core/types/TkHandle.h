#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class TkHandle
{
  public:
    enum
    {
        NumLookupBits      = 0x12,
        NumIncrementorBits = 0xE,
        InvalidLookup      = 0x3FFFF,
    };

    union {
        struct
        {
            uint32_t miLookup : NumLookupBits;
            uint32_t miIncrementor : NumIncrementorBits;
        };
        uint32_t miLookupInt;
    };

    uint64_t GetLookup() { return this->miLookupInt & InvalidLookup; }

    TkHandle *Root(TkHandle *result)
    {
        result->miLookup = 0x40000;
        return result;
    }

    bool operator==(TkHandle lHandle)
    {
        return ((lHandle.miLookupInt ^ this->miLookupInt) & InvalidLookup) == 0 &&
               ((lHandle.miLookupInt ^ this->miLookupInt) & 0xFFFC0000) == 0;
    }

    bool operator!=(TkHandle lHandle)
    {
        return ((lHandle.miLookupInt ^ this->miLookupInt) & InvalidLookup) != 0 &&
               ((lHandle.miLookupInt ^ this->miLookupInt) & 0xFFFC0000) != 0;
    }
};

SKYSCRAPER_END