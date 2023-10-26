#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

template <class T, typename U, unsigned int liLength>
class cTkFunctionPointerArray
{
	T mapArray[liLength];
	U* mapDataArray[12];
	int miNumPointers;
};

SKYSCRAPER_END