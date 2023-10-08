#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/TkString.h>

SKYSCRAPER_BEGIN

class cTkClassPointer
{
public:
	union cTkClassPointerData
	{
		void *mpClass;
		__int64 miOffset;
	};

	cTkClassPointer::cTkClassPointerData mClassData;
	cTkFixedString<63, char> mClassName;
	bool mbClassFixed;
	unsigned __int64 mClassNameHash;
};

SKYSCRAPER_END