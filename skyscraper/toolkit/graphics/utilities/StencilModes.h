#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

namespace StencilModes
{
	enum List 
	{
		Disabled,
		MaskWrite,
		MaskRead,
		MaskReadInvert,
		MaskWriteInside,
		MaskWriteOnce,
		MaskReadWriteNotEqual,
		MaskReadWriteInvert,
		MaskReadWrite,
	};
}

SKYSCRAPER_END