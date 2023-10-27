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