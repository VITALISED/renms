/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <skyscraper.h>
#include <simulation/player/GcPlayerEffect.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <metadata/source/simulation/components/effects/gcplayereffectscomponentdata.meta.h>

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