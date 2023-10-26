#pragma once

#include <skyscraper.h>
#include <toolkit/simulation/components/TkAnimationComponent.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <metadata/toolkit/components/audio/tkaudiocomponentdata.meta.h>

SKYSCRAPER_BEGIN

class cTkAudioComponent : public cTkComponent
{
	cTkAudioComponentData* mpData;
	std::array<int, 256> miFrameTracker;
	cTkStackVector<short> miAnimIndices;
	int miNumAnimTriggers;
	cTkAnimationComponent* mpAnimation;
	bool mbCreature;
	TkAudioObject mAudioObject;
	bool mbAmbientActive;
	bool mbMuted;
	bool mbShuttingDown;
	int miBreakOnAnimTrigger;
};

SKYSCRAPER_END