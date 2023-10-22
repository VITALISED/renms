#pragma once

#include <skyscraper.h>
#include <networking/GcNetworkRpcId.h>
#include <networking/GcNetworkRpcMessage.h>

SKYSCRAPER_BEGIN

class cGcRpcCallBase
{
    cGcNetworkRpcId mID;

    virtual ~cGcRpcCallBase();
    virtual void Update(float);
    virtual void ProcessRemoteCall(cGcNetworkRpcMessage *, cGcNetworkPlayer *);
    virtual void ProcessResponse(cGcNetworkRpcMessage *, cGcNetworkPlayer *);
};

SKYSCRAPER_END