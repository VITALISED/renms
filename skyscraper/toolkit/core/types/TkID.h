#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

template <uint32_t Size>
union TkID {
    TkID();

    TkID(const char *lpacString)
    {
        // uses hashes pretty sure, gonna have to figure out spookyhash later
        strcpy_s(mChars, Size, lpacString);
    }

    char mChars[Size / 8];
    uint64_t mUInt64[Size / 64];
};

template <uint32_t Size>
struct TkIDHashed
{
    TkID<Size> mID;
    uint64_t mHash;
};

SKYSCRAPER_END