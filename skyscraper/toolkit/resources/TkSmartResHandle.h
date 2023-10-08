#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/TkStrongType.h>

SKYSCRAPER_BEGIN

class cTkSmartResHandle
{
public:
	TkStrongType<int, TkStrongTypeIDs::TkResHandleID> miInternalHandle;
};

SKYSCRAPER_END