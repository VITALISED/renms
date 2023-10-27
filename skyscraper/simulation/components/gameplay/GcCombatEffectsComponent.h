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