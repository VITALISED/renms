#pragma once

#include <skyscraper.h>
#include <toolkit/attachments/TkHandle.h>
#include <toolkit/simulation/physics/TkPhysicsProperties.h>

SKYSCRAPER_BEGIN

enum eBodyOwnerType
{
  	HumanPlayer,
  	NPC,
  	Vehicle,
  	Camera,
  	NA,
};

class cTkRigidBodyPtr
{
	int miBodyIndex;
	__int64 miUniqueID;
};

class cTkRigidBodyProxy
{
  	cTkPhysRelMat34 mTransform;
  	cTkVector3 mvLinearVelocity;
  	cTkVector3 mvAngularVelocity;
  	cTkCharacterRigidBody *mpCharBody;
  	unsigned int mBodyIdInt;
  	int miIndex;

  	struct 
	{
  		__int8 mbTransformDirty : 1;
  		__int8 mbLinVelDirty : 1;
  		__int8 mbAngVelDirty : 1;
  		__int8 mbActivate : 1;
  		__int8 mbRebuildCaches : 1;
  		__int8 mbConvertToKeyframed : 1;
  		__int8 mbUpdatePrePhysics : 1;
  		__int8 mbUpdateContact : 1;
  		__int8 mbReintegrateMotion : 1;
  		__int8 mbDisableContactResponse : 1;
  		__int8 mbEnableContactResponse : 1;
  		__int8 mbStatic : 1;
  		__int8 mbKeyframed : 1;
  		__int8 mbInWorld : 1;
	} mFlags;
};

class cTkRigidBody
{
  	hkVector4f mvFactor;
  	hknpMassDistribution mMassDistribution;
  	cTkPhysicsProperties mProperties;
  	cTkRigidBodyProxy *mRigidBodyProxy;
  	cTkCollision *mpCollision;
  	cTkPhysicsComponent *mPhysicsComponent;
  	cTkStaticPhysicsComponent *mpStaticPhysicsComponent;
  	eTkRigidBodyGameplayFlags mxGameplayFlags;
  	TkHandle miOrder1;
  	TkHandle miOrder2;
  	unsigned __int64 miUniqueID;
  	TkHandle mNode;
  	unsigned int miIndex;
  	float mfMaxClimbableSlopeDegrees;
  	float mfMaxLinearSpeed;
  	unsigned __int16 miFilterGroup;
  	unsigned __int16 miFilterMask;
  	cTkBitArray<unsigned int,1,32> mKinematicFlags;

	struct
	{
  		__int8 mbIsTerrain : 1;
 		__int8 mbHasContacts : 1;
  		__int8 mbUseCharacterPhysics : 1;
  		__int8 mbFlipBackfacingCollisions : 1;
  		__int8 mbHasForcedMassProps : 1;
  		__int8 mbIsTriggerVolume : 1;
 		__int8 mbIsTriggered : 1;
  		__int8 mbCollidesWithPlayerVehicle : 1;
  		__int8 mbDestroyedByPlayerVehicle : 1;
  		__int8 mbDestroyedByPlayerShip : 1;
  		__int8 mbDisableContactCaching : 1;
  		__int8 mbCameraInvisible : 1;
  		__int8 mbMarkedAsPlayerShip : 1;
  		__int8 mbMarkedAsNoShipCollide : 1;
  		__int8 mbMarkedAsPlayerVehicle : 1;
  		__int8 mbClimbable : 1;
  		__int8 mbRagdoll : 1;
	} mFlags;
  
  	eBodyOwnerType mBodyOwnerType;
};

SKYSCRAPER_END