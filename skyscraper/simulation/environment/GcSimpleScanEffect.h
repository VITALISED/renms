#pragma once

#include <skyscraper.h>
#include <simulation/player/GcPlayerEmoteProp.h>
#include <toolkit/maths/numeric/TkSmoothCD.h>
#include <metadata/simulation/player/gcscaneffectdata.meta.h>

SKYSCRAPER_BEGIN

class cGcSimpleScanEffect
{
	typedef cGcPlayerEmoteProp::eState eState;

	cGcScanEffectData* mpSourceData;
	cGcScanEffectData mData;
	cTkSmoothCD<float> mScanPower;
	TkHandle mScanNode;
	cTkColour mColour;
	bool mbColourOverride;
	cGcSimpleScanEffect::eState meState;
};

SKYSCRAPER_END