#pragma once

#include <skyscraper.h>
#include <simulation/ecosystem/creatures/GcCreatureFullBodyIkComponent.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>
#include <metadata/simulation/vehicles/gcvehicledata.meta.h>
#include <metadata/simulation/vehicles/gcmechdebugspawndata.meta.h>
#include <metadata/simulation/vehicles/gcmechmeshtype.meta.h>
#include <metadata/simulation/vehicles/gcmechweaponlocation.meta.h>

SKYSCRAPER_BEGIN

class cGcMechControl
{
	enum eMechJumpState
	{
		EMechJumpState_None,
		EMechJumpState_WindUp,
		EMechJumpState_TakeOff,
		EMechJumpState_InAir,
		EMechJumpState_Land,
		EMechJumpState_NumTypes = 5,
	};

	enum eMechAnimState
	{
		EMechAnimState_Idle,
		EMechAnimState_Stunned,
		EMechAnimState_Loco,
		EMechAnimState_PrepareToJump,
		EMechAnimState_Jump,
		EMechAnimState_Land,
		EMechAnimState_NumTypes = 6,
	};

	enum eMechTitanFallState
	{
		EMechTitanFallState_None,
		EMechTitanFallState_Falling,
		EMechTitanFallState_Pose,
	};

	enum eMechPilotState
	{
		EMechPilotState_Inactive,
		EMechPilotState_Entering,
		EMechPilotState_PowerUp,
		EMechPilotState_Active,
	};

	enum eMechStunState
	{
		EMechStunState_None,
		EMechStunState_Active,
	};

	enum eMechPilotType
	{
		EMechPilotType_None,
		EMechPilotType_Player,
		EMechPilotType_AI,
		EMechPilotType_NumTypes = 3,
	};

	class cGcWeaponAimData
	{
		cTkPhysRelVec3 mvAimTargetPos;
		eMechWeaponLocation meActiveWeaponLocation;
	};

	class cGcArmAimInfo
	{
		TkHandle mPitchJointNode;
		cTkMatrix34 mInitLocalMat;
		cTkAnimLayerHandle mPitchLayer;
	};

	class cGcResummonRequest
	{
		bool mbIsPending;
		cTkPhysRelMat34 mTargetMatrix;
	};

	class cGcFootInfo
	{
		TkHandle muNode;
		cTkPhysRelVec3 mvPreviousPos;
		cTkPhysRelVec3 mvLastDustPos;
		bool mbPlanted;
	};

	class cGcFootPrintInfo
	{
		enum eFootprintState
		{
			EFootprintState_Inactive,
			EFootprintState_Active,
			EFootprintState_Fading,
		};

		TkHandle muNode;
		cGcFadeNode mFade;
		cGcMechControl::cGcFootPrintInfo::eFootprintState meState;
		float mfActiveTime;
	};

	class cGcContrailInfo
	{
		TkHandle mAttachNode;
		TkHandle mContrailNode;
	};

	class cGcJetpackElement
	{
		TkHandle mAttachNode;
		TkHandle mLightNode;
		EffectInstance mEffectHandle;
	};

	cGcVehicleData* mpVehicleData;
	cTkRigidBody* mpVehicleBody;
	cGcCreatureFullBodyIKComponent* mpCreatureIK;
	cTkHavokCharacterController* mpPhysicsController;
	TkAudioObject mAudioObject;
	cTkAnimationComponent* mpAnimation;
	bool mbOnGround;
	bool mbJumpButtonHeld;
	bool mbWantsToRun;
	bool mbRunning;
	bool mbThirdPerson;
	bool mbBeingCustomised;
	bool mbStrafeMode;
	cTkVector3 mvDesiredTurretFacing;
	cTkVector3 mvCameraRelativeStick;
	bool mbIsUnderwater;
	float mfLookTurn;
	float mfLookPitch;
	cTkAudioComponent* mpAudioComponent;
	float mfSmoothRunSpeedInterp;
	cTkSmoothCD<cTkVector3> mvTurretAngles;
	cTkSmoothCD<cTkVector3> mvCoGAdjust;
	cTkSmoothCD<float> mfFootConstraintStrength;
	cTkSmoothCD<float> mfSmoothTerrainAngle;
	cTkSmoothCD<float> mfCameraRotationOffset;
	cTkSmoothCD<float> mfAvoidGroundStrength;
	cTkSmoothCD<float> mfFootGlueStrength;
	cTkSmoothCD<float> mfBobStrength;
	float mfJumpWindUp;
	float mfJetpackAmount;
	float mfIgnitionTime;
	float mfLandSpeed;
	float mfLastLandTime;
	bool mbSkidL;
	float mfSkidSteerStrength;
	bool mbWasIgnited;
	bool mbPhysicsEnabled;
	cGcAnimationLayerQueue mAnimQueue;
	cGcMechControl::eMechJumpState meJumpState;
	cGcMechControl::eMechAnimState meState;
	cGcMechControl::eMechAnimState mePreviousState;
	float mfTimeInState;
	cGcMechControl::eMechTitanFallState meTitanFallState;
	cGcMechControl::eMechPilotState mePilotState;
	cGcMechControl::eMechPilotType mePilotType;
	cGcMechControl::eMechStunState meStunState;
	TkHandle mEyeLocator;
	cGcMechDebugSpawnData* mpDebugSpawnData;
	float mfDebugTimer;
	bool mbTerrainEditOnLand;
	eMechMeshType maeActiveMechPartTypes[5];
	cGcMechControl::cGcWeaponAimData mWeaponAimData;
	cGcMechControl::cGcArmAimInfo mLeftArmAimInfo;
	cGcMechControl::cGcArmAimInfo mRightArmAimInfo;
	cGcMechControl::cGcResummonRequest mResummonRequest;
	cGcMechControl::cGcFootInfo maFeet[2];
	cGcMechControl::cGcFootPrintInfo maFootPrints[16];
	TkHandle mFootprintGroupNode;
	cTkVector<cGcMechControl::cGcContrailInfo> maContrails;
	cTkSmoothCD<float> mfSmoothVerticalSpeed;
	cTkSmoothCD<float> mfContrailFactor;
	cTkVector<cGcMechControl::cGcJetpackElement> maJetpackElements[2];
	cTkSmoothCD<cTkVector3> mvSmoothJetDir;
	EffectInstance mLaunchGroundEffectHandle;
	EffectInstance mLandingImpactEffectHandle;
};

SKYSCRAPER_END