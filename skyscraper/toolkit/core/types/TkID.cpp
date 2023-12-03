#include <toolkit/core/types/TkID.h>

SKYSCRAPER_BEGIN

template <uint32_t Size>
uint64_t TkID<Size>::CalcHash()
{
    uint64_t hashVal = TK_FNV_OFFSET_BASIS;

    for (int i = 0; i < sizeof(this.mChars); i++)
    {
        hashVal ^= this->mChars[i];
        hashVal *= TK_FNV_PRIME;
    }

    return hashVal;
}

SKYSCRAPER_END