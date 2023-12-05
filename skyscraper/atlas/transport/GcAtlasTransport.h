/**
 * @file GcAtlasTransport.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
 * 
 * Copyright (C) 2023  VITALISED & Contributors
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

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