#pragma once

#include <skyscraper.h>
#include <networking/GcNetworkMessage.h>

SKYSCRAPER_BEGIN

class cGcNetworkDelayedMessage : public cGcNetworkMessage
{
    unsigned __int64 mDoNotProcessBefore;
    bool mbDelayed;
};

SKYSCRAPER_END