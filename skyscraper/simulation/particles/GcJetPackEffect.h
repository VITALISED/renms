#pragma once

#include <skyscraper.h>
#include <simulation/EffectInstance.h>

SKYSCRAPER_BEGIN

class cGcJetpackEffect
{
	TkHandle mParentNode;
	TkHandle mJetMeshNode;
	TkHandle mTrailNode;
	TkHandle mTrailSceneNode;
	TkID<128> mEffectId;
	EffectInstance mEffectHandle;
	EffectInstance mUnderwaterEffectHandle;
	cTkMatrix34 mInactiveMatrix;
	cTkMatrix34 mActiveMatrix;
};

SKYSCRAPER_END