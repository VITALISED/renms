#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class cGcNetworkAddress
{
    virtual bool operator==(const cGcNetworkAddress *);
};

SKYSCRAPER_END