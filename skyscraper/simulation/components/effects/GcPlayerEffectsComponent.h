#pragma once

#include <skyscraper.h>
#include <simulation/player/GcPlayerEffect.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <metadata/simulation/components/effects/gcplayereffectscomponentdata.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerDissapearEffect : public cGcPlayerEffect
{
	ePlayerEffects meEffect;
	cTkSmartResHandle mVehicleEnterExitEffectRes;
	TkHandle mVehicleEnterExitNode;
	float mfEffectTime;
	bool mbStartedEffect;
	bool mbDissolveStarted;
};

class cGcPlayerEffectsComponent : public cTkComponent
{
	struct Dissolve
	{
		struct  Data
		{
			enum eDissolveType
			{
				EDissolveType_Appear_Up,
				EDissolveType_Appear_Down,
				EDissolveType_Dissapear_Up,
				EDissolveType_Dissapear_Down,
				EDissolveType_None,
			};

			bool mbDissolve;
			cGcPlayerEffectsComponent::Dissolve::Data::eDissolveType meDissolveType;
			bool mbHideAbove;
			cTkVector3 mvDissolveDirection;
			float mfDissolveStart;
			float mfDissolveEnd;
			float mfDissolveTimer;
			float mfDissolveTime;
			bool mbForceHide;
		};

		cGcPlayerEffectsComponent::Dissolve::Data mData;
		TkHandle mNode;
	};

	cGcPlayerEffectsComponent::Dissolve mBodyDissolve;
	cGcPlayerEffectsComponent::Dissolve mHeadDissolve;
	cGcPlayerEffectsComponent::Dissolve maHandsDissolve[2];
	cGcPlayerEffectsComponent::Dissolve mWeaponDissolve;
	cGcPlayerEffectsComponentData* mpData;
	TkHandle mModelNode;
	ePlayerEffects meEffectToStart;
	ePlayerEffects meCurrentEffect;
	float mfEffectSpeed;
	cGcPlayerDissapearEffect mPlayerDissapearEffect;
	cGcPlayerEffect* mpCurrentEffect;
};

SKYSCRAPER_END