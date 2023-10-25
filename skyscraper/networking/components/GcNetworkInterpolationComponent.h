#pragma once

#include <skyscraper.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>
#include <toolkit/maths/numeric/TkQuaternion.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>
#include <metadata/simulation/components/networking/gcnetworkinterpolationcomponentdata.meta.h>

SKYSCRAPER_BEGIN

class cGcNetworkInterpolationComponent : public cTkComponent
{
	struct MovementSnapshot
	{
		unsigned __int64 luTime;
		cTkPhysRelVec3 mPosition;
		cTkQuaternion mRotation;
		cTkVector3 mVelocity;
		cTkVector3 mAngularVelocity;
		bool mNodeActive;
		bool mbTeleporting;
	};

	cGcNetworkInterpolationComponentData* mpData;
	std::deque<cGcNetworkInterpolationComponent::MovementSnapshot> mMovementSnapshots;
	cTkPhysRelMat34 mCurrentLocation;
	cTkPhysRelVec3 mCurrentPosition;
	cTkPhysRelVec3 mPositionOverride;
	cTkVector3 mCurrentVelocity;
	cTkVector3 mVelocityOverride;
	cTkVector3 mCurrentAngularVelocity;
	cTkVector3 mAngularVelocityOverride;
	cTkQuaternion mCurrentRotation;
	cTkQuaternion mRotationOverride;
	cTkVector3 mCurrentScale;
	cTkRigidBody* mpRigidBody;
	bool mbIsActive;
	bool mbHasMarker;
	bool mbTeleporting;
	bool mbRecentlyTeleported;
	bool mbOverrideToBeInactive;
	float mfTimeSinceLastUpdateRecvd;
	float mCurrentLatency;
};

SKYSCRAPER_END