#pragma once

#include <skyscraper.h>
#include <toolkit/system/memory/pools/TkMemoryPool.h>

SKYSCRAPER_BEGIN

class cTkLinearMemoryPool : public cTkMemoryPool
{
	typedef void (*Create)(
		cTkLinearMemoryPool *thiscall,
		void *lpAlloc,
		size_t liBufferSize,
		unsigned int liBufferAlignment);
	typedef void (*Malloc)(
		cTkLinearMemoryPool *thiscall,
		int liSize,
		int liAlignment,
		int *lpiAllocatedSize);

	// void* mpAllocAddress;
	// unsigned __int64 miStartAddress;
	// unsigned __int64 miEndVirtualAddress;
	// unsigned __int64 miEndMappedAddress;
	// unsigned __int64 miNextAddress;
	// void* mpLastAllocation;
	//__int64 miHighWater;
	// unsigned __int64 miUserData;
	// bool mbCreated;
	// bool mbVirtualBacked;
};

SKYSCRAPER_END