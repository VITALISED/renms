#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class cTkClock
{
	unsigned __int64 mu64StartTime;
	unsigned __int64 mu64CurrentTime;
	unsigned __int64 muLastWaitTicksFinish;
	float mfTimeStep;
	float mfTotalTime;
	float mfPrevTotalTime;
	float mfSlowMotionFactor;
	unsigned __int64 muFrameCount;
	bool mbMinFrameTimeSynced;
	bool mbPaused;
	bool mbRealtime;
};

SKYSCRAPER_END