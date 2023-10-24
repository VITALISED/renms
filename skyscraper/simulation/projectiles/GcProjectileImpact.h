#pragma once

#include <skyscraper.h>
#include <simulation/player/GcOwnerConcept.h>
#include <simulation/player/GcPlayer.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <metadata/simulation/projectiles/gcdamagetype.meta.h>
#include <metadata/gameplay/gccombateffecttype.meta.h>
#include <metadata/gameplay/gcimpactcombateffectdata.meta.h>
#include <metadata/simulation/projectiles/gccombateffectdamagemultiplier.meta.h>

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