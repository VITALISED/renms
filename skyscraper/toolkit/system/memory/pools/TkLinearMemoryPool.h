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