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
#include <simulation/player/GcOwnerConcept.h>
#include <simulation/player/GcPlayer.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <metadata/source/simulation/projectiles/gcdamagetype.meta.h>
#include <metadata/source/gameplay/gccombateffecttype.meta.h>
#include <metadata/source/gameplay/gcimpactcombateffectdata.meta.h>
#include <metadata/source/simulation/projectiles/gccombateffectdamagemultiplier.meta.h>

SKYSCRAPER_BEGIN

class cGcProjectileImpact
{
	typedef cGcPlayer::eRocketBootsDoubleTapState InstantKill;

	cTkMatrix34 mMatrix;
	cTkVector3 mDirection;
	cTkRigidBodyPtr mpImpactBody;
	int miImpactMaterial;
	cGcOwnerConcept* mpOwnerConcept;
	cTkAttachmentPtr mOwnerAttachment;
	float mfTime;
	int miDamage;
	eDamageType meDamageType;
	eCombatEffectType meCombatEffectType;
	float mfExplosionRadius;
	float mfLeechValue;
	TkID<128> mProjectileID;
	TkID<128> mPlayerDamage;
	cGcProjectileImpact::InstantKill meInstantKill;
	bool mbCrit;
	bool mbLaserBoost;
	bool mbIsPiercingImpact;
	bool mbRemoteMessage;
	cTkVector<cGcImpactCombatEffectData> maCombatEffects;
	cTkVector<cGcCombatEffectDamageMultiplier> maDamageMultipliers;
};

SKYSCRAPER_END