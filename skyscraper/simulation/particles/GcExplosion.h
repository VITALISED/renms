#pragma once

#include <skyscraper.h>
#include <simulation/scenemanager/GcFadeNode.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/simulation/physics/TkPhysicsComponent.h>
#include <metadata/simulation/particles/gcexplosiondata.meta.h>

SKYSCRAPER_BEGIN

class cGcExplosion
{
	class cGcDebris
	{
		cGcFadeNode mFade;
		TkHandle mNode;
		cTkPhysicsComponent* mpPhysics;
	};

	const cGcExplosionData* mpData;
	cTkMatrix34 mOffset;
	TkHandle mNode;
	TkHandle mParent;
	bool mbUpdateFromParent;
	int miNumDebris;
	TkHandle mDebrisNode;
	std::array<cGcExplosion::cGcDebris, 16> maDebris;
	TkID<128> mUserColourId;
	cTkColour mUserColour;
	TkAudioObject mAudioObject;
	float mfLife;
	bool mbIsPermanent;
	bool mbUserColourChanged;
};

SKYSCRAPER_END