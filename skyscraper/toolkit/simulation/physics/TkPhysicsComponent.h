#pragma once

#include <skyscraper.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <toolkit/utilities/containers/TkStackVector.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/simulation/physics/havok/TkCollision.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>
#include <toolkit/simulation/physics/havok/TkPhysicsConstraint.h>
#include <metadata/components/physics/tkphysicscomponentdata.meta.h>
#include <metadata/components/physics/tkdynamicchaincomponentdata.meta.h>
#include <metadata/physics/ragdoll/tkragdolldata.meta.h>

SKYSCRAPER_BEGIN

class cTkPhysicsComponent : public cTkComponent
{
	struct SubBody
	{
		cTkCollision* mpColl;
		cTkRigidBody* mpBody;
		cTkPhysicsConstraint* mpConstraint;
		TkHandle muNode;
		cTkVector3 mvScale;
		cTkDynamicChainComponentData* mpChainData;
		cTkRagdollData* mpRagdollData;
	};

	struct RagdollVelTracker
	{
		cTkVector3 mvPrevLoc;
		TkHandle muNode;
		int miParentInd;
		bool mbChainEnd;
	};

	cTkPhysicsComponentData* mpData;
	TkHandle muNode;
	cTkRigidBody mRigidBody;
	cTkCollision mCollision;
	cTkCollision mComplexCollision;
	TkHandle mNextNodeToBuildCollision;
	cTkStackVector<TkHandle> maNodesToIgnoreBuildingCollision;
	cTkMatrix34 mGraphicsToPhysics;
	cTkMatrix34 mPhysicsToGraphics;
	cTkVector3 mGraphicsScale;
	float mfAirThicknessMult;
	float mfMotorStrengthMult;
	float mfWindStrengthMult;
	float mfRagdollTau;
	float mfRagdollDamping;
	float mfRagdollConeLimit;
	float mfRagdollTwistLimit;
	float mfRagdollJointFriction;
	float mfRagdollGravityFactor;
	float mfRagdollLinearDamping;
	float mfRagdollTauFadeStartTime;
	float mfRagdollTauFadeEndTime;
	float mfRagdollLifetime;
	int miRagdollFrameCountdown;
	int miRagdollImpactFrameCnt;
	unsigned __int16 muRagdollCollisionMask;
	cTkVector3 mvRagdollInitialVelocity;
	bool mbPrepared;
	bool mbLevelGraphicsMatrix;
	bool mbForceGraphicsFollow;
	bool mbModelOwnerSearched;
	bool mbIsModelOwner;
	bool mbRagdollRequested;
	bool mbHasJointChain;
	bool mbHasRagdolled;
	bool mbUsingRagdollCollision;
	bool mbExplodeRequested;
	bool mbHasCodeDrivenSubBodies;
	bool mbHasExploded;
	bool mbIsExplosionType;
	float mfExplodeCollsionCountdown;
	bool mbPhysicsUpdateFromGraphicsEnabled;
	bool mbUsingSimpleCollision;
	bool mbUsingSimpleCharacterCollision;
	bool mbBreakOnPostPhysUpdate;
	bool mbDraw;
	bool mbDrawJointHierarchy;
	bool mbPrintSkel;
	TkHandle mHighlightedNode;
	TkHandle mSelectedNode;
	cTkVector3 mvRagdollImpactDir;
	cTkVector3 mvRagdollImpactPos;
	cTkVector<cTkPhysicsConstraint*> mapConstraints_;
	cTkVector<cTkPhysicsComponent::SubBody> maSubBodies;
	cTkVector<cTkPhysicsComponent::RagdollVelTracker> maVelTrackers;
	cTkVector<int> maJointsToUpdateTransformsForInRagdoll;
};

SKYSCRAPER_END