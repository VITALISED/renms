#pragma once

#include <skyscraper.h>
#include <toolkit/system/memory/pools/TkMemoryPool.h>
#include <metadata/user/gcblocklistpersistence.meta.h>

SKYSCRAPER_BEGIN

class cGcBlockList
{
	struct Data : AutoPooled<EMemoryPool_Network>
	{
		cGcBlockListPersistence* mBlockListArray;
	};

	cGcBlockList::Data* mpData;
};


SKYSCRAPER_END