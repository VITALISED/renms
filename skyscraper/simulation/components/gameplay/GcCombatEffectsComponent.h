#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <simulation/components/utils/GcPlayerCharacterComponent.h>
#include <metadata/simulation/components/gameplay/gccombateffectscomponentdata.meta.h>
#include <metadata/gameplay/gcimpactcombateffectdata.meta.h>

SKYSCRAPER_BEGIN

class cGcShootableComponent;

class sGActiveCombatEffectData
{
	cGcImpactCombatEffectData mEffectData;
	cGcOwnerConcept* mpOwnerConcept;
	cTkAttachmentPtr mOwnerAttachment;
	cTkRigidBodyPtr mpImpactBody;
};

class cGcCombatEffectsComponent : public cTkComponent
{
	cGcCombatEffectsComponentData* mpData;
	bool mbIsPrepared;
	cGcPlayerCharacterComponent* mpPlayerCharacterComp;
	cGcShootableComponent* mpShootableComp;
	TkAudioObject mAudioObject;
	TkHandle mVFXNode;
	cTkFixedArray<int, 4> maiEffectsInstancesCount;
	cTkFixedArray<EffectInstance, 4> mEffectsParticles;
	cTkVector<sGActiveCombatEffectData> maActiveEffectsData;
};

SKYSCRAPER_END