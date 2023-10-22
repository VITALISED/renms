#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class cGcNetworkRpcId
{
    union
    {
        char macID[4];
        unsigned int miIdNum;
    };
};

SKYSCRAPER_END