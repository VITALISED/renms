#pragma once

#include <skyscraper.h>
#include <networking/GcNetworkDelayedMessage.h>

SKYSCRAPER_BEGIN

class cGcNetworkRpcMessage : public cGcNetworkDelayedMessage
{
    unsigned int mRpcId;
    unsigned int mInstanceId;
};

SKYSCRAPER_END