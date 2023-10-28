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
#include <simulation/ecosystem/creatures/GcCreatureNavigation.h>
#include <toolkit/simulation/components/TkAudioComponent.h>
#include <toolkit/animation/utils/TkIKSolver.h>
#include <toolkit/maths/geometry/TkAABB.h>
#include <toolkit/simulation/physics/TkRaycastJob.h>
#include <simulation/GcCharacterInterface.h>
#include <metadata/source/simulation/components/player/gcplayerfullbodyikcomponentdata.meta.h>
#include <metadata/source/simulation/ecosystem/creatures/data/gccreaturefootparticledata.meta.h>

SKYSCRAPER_BEGIN

class cGcHandTrackingConstraint : cTkIKJointHeightConstraint
{
	cTkMatrix34 mDesiredMatrix;
	cTkMatrix34 mPreSolveMatrix;
	int miElbowIndex;
	int miShoulderIndex;
	float mfForearmDirection;
	bool mbWristLocked;
	bool mbForceInitialPose;
};

class cGcHeadConstraint : cTkIKConstraint
{
	cTkEulerVector mvDesiredRot;
	cTkVector3 mvHeadPreAdditive;
	cTkVector3 mvDesiredPos;
	TkHandle muNode;
	int mBoneIndex;
	int mJointIndex;
	cTkEulerVector mvRotChange;
	cTkVector3 mvHeadPostIkModelSpacePos;
	cTkVector3 mvRotStrengths;
	float mfHeadMoveScale;
	float mfRotStrength;
	float mfPosStrength;
	float mfAdjustHeight;
	bool mbEnablePos;
	bool mbEnableRot;
};

class cGcFootConstraint : cTkIKJointHeightConstraint
{
	cGcCreatureNavTrail* mpNavTrail;
	cGcFootConstraint* mpParentFoot;
	cTkVector3 mvFootJointSpacePos;
	cTkVector3 mvFootModelSpacePos;
	cTkVector3 mvFootModelSpaceOffset;
	cTkMatrix34 mvFootPostIkModelSpaceT;
	cTkVector3 mvTrailAdjust;
	cTkPhysRelVec3 mvWorldSpacePlantPos;
	cTkPhysRelMat34 mModelMat;
	float mfFootHeightPrePose;
	cTkEulerVector mvFootRotPrePose;
	float mfFootHold;
	float mfPrevFootHold;
	float mfFootHoldSpeed;
	float mfDeltaTime;
	float mfModelBaseHeight;
	int miFrameCounter;
	int miShoulderBoneIndex[2];
	int miPelvisBoneIndex;
	float mfPreAddLegLength;
	float mfPostAddLegLength;
	float mfFootMoveScale;
	float mfFootPlantedTolerance;
	float mfFootPlantSpring;
	float mfMaxFootTrailAdjust;
	ePrimaryAxis meAxis;
	bool mbIsRealFoot;
	bool mbFootPlanted;
	bool mbUseFootGlue;
	float mfGlueStrength;
};

class cGcPlayerFullBodyIKComponent : public cTkComponent
{
	struct IkPush
	{
		cTkIKJointXZPushConstraint mProjectileHitConstraint;
		cTkVector3 mvCreaturePushDirection;
		float mfCreatureIkPushTime;
		cTkAABB mLocalAabb;
		bool mbActive;
	};

	cTkPreAdditiveCallbackForwarder<cGcPlayerFullBodyIKComponent> mPreAdditiveCallbackForwarder;
	cTkOnPostAnimCallbackForwarder<cGcPlayerFullBodyIKComponent> mOnPostAnimCallbackForwarder;
	cGcPlayerFullBodyIKComponentData* mpData;
	TkHandle muNode;
	cTkIKFullBody mIk;
	std::vector<cTkIKFullBody::ActiveAxes> maPreviousJointAxes;
	cGcCharacterInterface* mpCharacterInterface;
	cTkAudioComponent* mpAudioComponent;
	cGcPlayerCharacterComponent* mpCharacterComponent;
	cTkStackVector<cGcHandTrackingConstraint> mHandConstraints;
	cTkStackVector<cGcHeadConstraint> mClavConstraints;
	cTkStackVector<cGcFootConstraint> mLegConstraints;
	cTkStackVector<cGcHeadConstraint> mRestrictConstraints;
	cGcHeadConstraint mHeadConstraint;
	cGcFootConstraint mSitConstraint;
	cGcCreatureCogConstraint mCoGConstraint;
	cTkStackVector<float> mContraintStateChangeSpring;
	cGcPlayerFullBodyIKComponent::IkPush maIkPushes[1];
	int miNumIkPushes;
	cTkRaycastJob mRayJob;
	cTkContactPoint mSlopeAngleContactResult;
	float mfMaxIterations;
	float mfMinIterations;
	float mfMaxIterationsDist;
	float mfMinIterationsDist;
	float mfCurrentSlopeAngle;
	cTkVector3 mCurrentSlopeContactNormal;
	float mfModelBaseHeight;
	float mfModelHeight;
	float mfMaxDimension;
	float mfXDimension;
	float mfZDimension;
	float mfIkPushStrength;
	float mfIkRotHoldStrength;
	float mfIkPushDistance;
	float mfStealthyCrouch;
	float mfFootMovePow;
	float mfAvgLegMult;
	float mfBanking;
	float mfTargetBanking;
	TkID<128> mWalkFootStepShake;
	float mfWalkFootShakeMaxDist;
	TkID<128> mRunFootStepShake;
	float mfRunFootShakeMaxDist;
	cGcCreatureFootParticleData* mpFootParticleData;
	cGcCreatureNavTrail* mpNavTrail;
	bool mbShowJoints;
	bool mbShowCapsules;
	bool mbShowAltCapsules;
	bool mbEnableFootRaycasts;
	bool mbDrawFootRaycasts;
	bool mbEnableDistanceIters;
	bool mbAdjustCogForFeet;
	bool mbUseRayForHead;
	bool mbUseFootAvgForHead;
	bool mbUsePelvises;
	bool mbShowLegJoints;
	bool mbBreakOnUpdatePostPhys;
	bool mbBreakOnFootstep;
	bool mbFootSoundDebugging;
	bool mbBodyLocked;
	bool mbIsSpaceship;
	bool mbIsRunning;
	bool mbEnabled;
};

SKYSCRAPER_END