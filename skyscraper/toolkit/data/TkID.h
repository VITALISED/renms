#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

template <unsigned int uiSize>
union TkID
{
	TkID()
	{ }
    
	TkID(const char *lpacString)
	{
		// uses hashes pretty sure, gonna have to figure out spookyhash later
		strcpy_s(mChars, uiSize, lpacString);
	}

	char mChars[uiSize / 8];
	unsigned __int64 mUInt64[uiSize / 64];
};

SKYSCRAPER_END