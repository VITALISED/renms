#pragma once

#include <skyscraper.h>
#include <toolkit/resources/TkSmartResHandle.h>
#include <toolkit/attachments/TkHandle.h>

SKYSCRAPER_BEGIN

class cGcBeamEffect
{
	cTkSmartResHandle mBeamRes;
	TkHandle mBeamNode;
	TkHandle mBeamLine;
	float mfYFactor;
	float mfTimeLeft;
	int miDamageLevel;
	bool mbActive;
};

SKYSCRAPER_END