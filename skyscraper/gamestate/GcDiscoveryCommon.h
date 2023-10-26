#pragma once

#include <skyscraper.h>
#include <toolkit/system/memory/pools/TkMemoryPool.h>
#include <metadata/reality/gcdiscoverytype.meta.h>

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