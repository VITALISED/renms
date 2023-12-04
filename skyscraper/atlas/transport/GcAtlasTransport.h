#pragma once

#include <skyscraper.h>

#include <toolkit/system/memory/pools/TkMemoryPool.h>
#include <toolkit/utilities/network/TkHttp.h>

SKYSCRAPER_BEGIN

namespace TransportNetworkState
{

typedef int Enum;

}

class cGcAtlasTransport : AutoPooled<5>
{
  public:
    typedef int RequestResult;

    virtual ~cGcAtlasTransport();
    virtual const char *GetName();
    virtual bool Construct();
    virtual void Destruct();
    virtual void Update();
    virtual void UpdateThreadStart();
    virtual void UpdateThreadEnd();
    virtual TransportNetworkState::Enum GetNetworkState();
    virtual bool IsTrafficInFlight();
    virtual cGcAtlasTransport::RequestResult RequestHttpAsync(
        const Http::Request *, const std::function<void __cdecl(Http::RequestResult const &)> *);
};

SKYSCRAPER_END