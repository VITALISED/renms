#pragma once

#include <skyscraper.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <metadata/simulation/components/gameplay/gccombateffectscomponentdata.meta.h>

SKYSCRAPER_BEGIN

class cGcShootableComponent;

class cGcCombatEffectsComponent : cTkComponent
{
	cGcCombatEffectsComponentData* mpData;
	bool mbIsPrepared;
	cGcPlayerCharacterComponent* mpPlayerCharacterComp;
	cGcShootableComponent* mpShootableComp;
	TkAudioObject mAudioObject;
	TkHandle mVFXNode;
	cTkFixedArray<int, 4> maiEffectsInstancesCount;
	cTkFixedArray<EffectInstance, 4> mEffectsParticles;
	std::vector<sGActiveCombatEffectData, TkSTLAllocatorShim<sGActiveCombatEffectData, 8, -1> > maActiveEffectsData;
};

SKYSCRAPER_END