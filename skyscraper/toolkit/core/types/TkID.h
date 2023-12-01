#pragma once

#include <skyscraper.h>

#include <toolkit/maths/utilities/hash/TkHashUtilities.h>

SKYSCRAPER_BEGIN

template <uint32_t Size>
union TkID {
    TkID();
    TkID(const char *lpacString) { strcpy_s(mChars, Size, lpacString); }
    uint64_t CalcHash();
    bool IsNull() { return !this->mUInt64[0] && !this->mUInt64[1]; }
    TkID<Size> operator=(const char *lpString)
    {
        if (!lpString) return this;

        strcpy_s(mChars, Size, lpString);
        return this;
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