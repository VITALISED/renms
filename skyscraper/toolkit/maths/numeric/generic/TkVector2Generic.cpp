#include "TkVector2Generic.h"

SKYSCRAPER_BEGIN

float cTkVector2::GetLength()
{
    float fVal = (this->mfX * this->mfX) + (this->mfY * this->mfY);

    return sqrtf(fVal);
}

SKYSCRAPER_END