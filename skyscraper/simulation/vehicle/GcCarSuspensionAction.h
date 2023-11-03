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
#include <simulation/VoxelType.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <metadata/source/simulation/vehicles/gcvehicledata.meta.h>

SKYSCRAPER_BEGIN

class cGcCarSuspensionAction /*: hknpAction*/
{
	struct WheelInfo
	{
		cTkPhysRelVec3 mvWorldStart;
		cTkPhysRelVec3 mvWorldEnd;
		cTkPhysRelVec3 mvWheelPos;
		cTkPhysRelVec3 mvWheelContactPos;
		cTkVector3 mvWheelContactNormal;
		float mfFraction;
		float mfSmoothedWheelForce;
		float mfCurWheelForce;
		int miWheelForceHistoryIndex;
		float mfWheelForceHistory[6];
		TkAudioObject mAudioObject;
		float mfLastAudioSuspension;
		float mfTimeSinceLastAudio;
		float mfLastAudioWheelForceStart;
		bool mbPreppingAudio;
		bool mbHasContact;
		eVoxelType meContactVoxel;
	};

	uintptr_t __vft; //TODO: fix havok stuff
	cGcVehicleData* mpVehicleData;
	cTkRigidBody* mpVehicleBody;
	hknpBodyId mVehicleId;
	bool mbAttract;
	cTkPhysRelMat34 mAttractTransform;
	int miNumWheels;
	bool mbOnGround;
	cTkVector3 mvCameraRelativeStick;
	cTkVector3 mvCameraRelativeThrottle;
	bool mbJumpForce;
	bool mbBoostForce;
	bool mbActive;
	bool mbAudioJumpStart;
	bool mbAudioJumpStarted;
	float mfAudioJumpForce;
	float mfBoostForceMultiplier;
	float mfBrake;
	bool mbGoForwards;
	float mfFrictionMultiplier;
	float mfSideFrictionMultiplier;
	float mfTopSpeedMultiplier;
	float mfAvgWheelSpin;
	float mfAvgWheelSlip;
	float mfAvgFwdForce;
	float mfAvgSideForce;
	cGcCarSuspensionAction::WheelInfo maWheels[10];
	float mafWheelRotate[10];
	float mafWheelOuterVel[10];
	float mafWheelFwdForce[10];
	float mafWheelSideForce[10];
	float mafWheelTurnForce[10];
	float mafWheelSlipSpeed[10];
	bool mbIsUnderwater;
	bool mbRemotePlayer;
};


SKYSCRAPER_END