#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/TkArray.h>

SKYSCRAPER_BEGIN

template <unsigned int size, typename T>
class cTkFixedString
{
public:
	cTkFixedString()
    { };

	cTkFixedString(const char *lpacBuffer)
	{
		this->Copy(lpacBuffer);
	}

	void Copy(const char *lpacBuffer);
	T macBuffer[size];
};

class cTkDynamicString : cTkDynamicArray<char>
{ };

SKYSCRAPER_END