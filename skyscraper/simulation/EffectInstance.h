#pragma once

#include <skyscraper.h>
#include <simulation/particles/GcExplosion.h>
#include <toolkit/attachments/TkHandle.h>

SKYSCRAPER_BEGIN

struct EffectInstance
{
	TkHandle mNodeHandle;
	cGcExplosion* mpExplosion;
	const cGcExplosionData* mpExplosionData;
};

SKYSCRAPER_END