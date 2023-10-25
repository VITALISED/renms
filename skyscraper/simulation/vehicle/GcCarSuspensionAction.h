#pragma once

#include <skyscraper.h>
#include <simulation/VoxelType.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <metadata/simulation/vehicles/gcvehicledata.meta.h>

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