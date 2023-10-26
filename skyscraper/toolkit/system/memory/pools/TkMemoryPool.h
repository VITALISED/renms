#pragma once

#include <skyscraper.h>
#include <toolkit/system/TkMemoryManager.h>

SKYSCRAPER_BEGIN

template<eTkMemType> class AutoPooled 
{ };

class cTkMemoryPool
{
public:
	// void* __vftable /*VFT*/;
	// int miType;
	// int miAlignment;
	// unsigned __int64 muTotalSize;
	// cTkBitArray<unsigned int, 32> mxErrors;
};

SKYSCRAPER_END