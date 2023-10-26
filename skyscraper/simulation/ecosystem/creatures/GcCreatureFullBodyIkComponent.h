#pragma once

#include <skyscraper.h>
#include <simulation/components/player/GcPlayerFullBodyIkComponent.h>
#include <simulation/ecosystem/creatures/GcCreatureNavigation.h>
#include <toolkit/simulation/components/TkComponent.h>
#include <toolkit/animation/utils/TkIKSolver.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <metadata/source/simulation/ecosystem/creatures/gccreaturefullbodyikcomponentdata.meta.h>

SKYSCRAPER_BEGIN

class cGcCreatureFullBodyIKComponent : public cTkComponent
{
	struct FootInfo
	{
		const cGcCreatureIkData* mpData;
		cTkPhysRelVec3 mvGroundPos;
		TkHandle muNode;
		cGcFootConstraint mConstraint;
		int mLimbIndex;
		int mDataIndex;
		int mJointIndex;
		eCreatureIkType meType;
		bool mbFound;
		bool mbDrawInfo;
	};

	struct IkPush
	{
		cTkIKJointXZPushConstraint mProjectileHitConstraint;
		cTkVector3 mvCreaturePushDirection;
		float mfCreatureIkPushTime;
		cTkAABB mLocalAabb;
		bool mbActive;
	};

	cGcCreatureFullBodyIKComponentData* mpData;
	TkHandle muNode;
	cTkIKFullBody mIk;
	cTkVector<cTkIKFullBody> mHeadIks;
	cTkVector<cTkIKFullBody> mLimbIks;
	cGcCreatureFullBodyIKComponent::FootInfo maFootJoints[16];
	int miNumFootJoints;
	int mNumLimbs;
	cTkVector<int> mJointDataIndexToLimbIndex;
	cTkVector<int> mFootIndexToLimbIndex;
	cTkVector<TkHandle> mJointDataNodes;
	bool mbUseFootGlue;
	const cGcCreatureIkData* mapHeadData[4];
	cGcHeadConstraint mHeadConstraints[4];
	int miNumHeads;
	cTkVector3 mfNeckAngles;
	cGcCreatureCogConstraint mCoGConstraint;
	cTkVector3 mvCoGOffset;
	int miNumKneeJoints;
	cGcCreaturePelvisConstraint mPelvisConstraints[48];
	int miNumPelvises;
	cGcPistonConstraint maPistonConstraints[16];
	int miNumPistons;
	cGcCreatureFullBodyIKComponent::IkPush maIkPushes[1];
	int miNumIkPushes;
	cTkRaycastJob mRayJob;
	float mfMaxIterations;
	float mfMinIterations;
	float mfMaxIterationsDist;
	float mfMinIterationsDist;
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
	unsigned int muCreatureClass;
	TkID<128> mWalkFootStepShake;
	float mfWalkFootShakeMaxDist;
	TkID<128> mRunFootStepShake;
	float mfRunFootShakeMaxDist;
	cTkColour mGroundEffectColour;
	cGcCreatureFootParticleData* mpFootParticleData;
	cGcCreatureNavTrail* mpNavTrail;
	bool mbEnableFootRaycasts;
	bool mbEnableDistanceIters;
	bool mbAdjustCogForFeet;
	bool mbUseRayForHead;
	bool mbUseFootAvgForHead;
	bool mbUsePelvises;
	bool mbBreakOnUpdatePostPhys;
	bool mbBreakOnFootstep;
	bool mbFootSoundDebugging;
	bool mbIsSpaceship;
	bool mbIsRunning;
	bool mbEnabled;
	bool mIsCreature;
	cTkVector<TkHandle> mCommonNodes;
	cTkMatrix34 mCommonNodeT;
	AnimTransform mCommonNodeAt;
	bool mCommonNodeHasBeenIntialised;
	cTkPreAdditiveCallbackForwarder<cGcCreatureFullBodyIKComponent> mPreAdditiveCallbackForwarder;
	cTkOnPostAnimCallbackForwarder<cGcCreatureFullBodyIKComponent> mOnPostAnimCallbackForwarder;
};

SKYSCRAPER_END