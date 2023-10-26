#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <metadata/toolkit/animation/tkhitcurvedata.meta.h>

SKYSCRAPER_BEGIN

class cTkHitCurve
{
	const cTkHitCurveData* mpData;
	cTkVector<std::pair<float, float> > mafHitTimes;
};

SKYSCRAPER_END