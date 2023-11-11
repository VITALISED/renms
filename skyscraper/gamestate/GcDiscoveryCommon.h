/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <skyscraper.h>

#include <toolkit/system/memory/pools/TkMemoryPool.h>

#include <reality/gcdiscoverytype.meta.h>

SKYSCRAPER_BEGIN

class cGcDiscoveryPayload : public AutoPooled<EMemoryPool_NodeAllocator>
{
    unsigned int kuSignificantElements;
    std::array<unsigned __int64, 5> mau64Storage;
    unsigned int muNumElements;
};

class cGcDiscoveryData : public AutoPooled<EMemoryPool_NodeAllocator>
{
    unsigned __int64 mUniverseAddress;
    cGcDiscoveryPayload mu64Payload;
    eDiscoveryType meType;
};

SKYSCRAPER_END