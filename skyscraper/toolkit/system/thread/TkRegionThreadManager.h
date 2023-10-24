#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

struct TkJobHandle
{
	int miQueue;
	int miIndex;
	unsigned __int64 muCount;
};

SKYSCRAPER_END