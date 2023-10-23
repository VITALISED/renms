#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

namespace WinHttpTask
{
	struct State
	{
		enum Enum
		{
			Invalid,
			Working,
			Complete,
			Failed,
			__EnumTerminator,
			Unspecified,
		};
	};
}

SKYSCRAPER_END