#pragma once

#include <skyscraper.h>
#include <metadata/utilities/input/tkinputvalidation.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerController
{
	virtual ~cGcPlayerController();
	virtual bool GetButtonInput(int, eInputValidation);
	virtual float GetAnalogInput(int);
};

SKYSCRAPER_END