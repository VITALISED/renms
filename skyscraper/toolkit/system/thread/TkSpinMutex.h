#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class cTkSpinMutex
{
	std::atomic<int> miLocked;
};

SKYSCRAPER_END