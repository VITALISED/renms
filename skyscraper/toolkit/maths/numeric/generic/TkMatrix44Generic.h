#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class cTkMatrix44
{
    union
    {
        float c[4][4];
        float x[16];
    };
};

SKYSCRAPER_END